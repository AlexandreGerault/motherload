#include "game.hpp"

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_timer.h>

#include <iostream>
#include <memory>

#include "components/animated_sprite_component.hpp"
#include "components/input_component.hpp"
#include "components/rigid_body_component.hpp"
#include "components/static_sprite_component.hpp"
#include "components/transform_component.hpp"
#include "sdl/sdl_renderer.hpp"
#include "systems/input_system.hpp"
#include "systems/render_system.hpp"
#include "textures.hpp"
#include "world.hpp"

using namespace mth;
using namespace mth::components;
using components::TransformComponent;

Game::Game() {
  SDL_CreateWindowAndRenderer("Motherload Rebirth", 860, 640,
                              SDL_WINDOW_MAXIMIZED, &m_window, &m_renderer);

  if (!m_window) {
    SDL_Log("Could not create window. SDL error: %s", SDL_GetError());
  }

  if (!m_renderer) {
    SDL_Log("Could not create renderer. SDL error: %s", SDL_GetError());
  }

  m_textureRegistry = SdlTextureRegistry{m_renderer};
}

Game::~Game() {
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void Game::loop() {
  SDL_Event e;
  SDL_zero(e);

  World myWorld{};

  m_textureRegistry.registerTexture(PLAYER_RUN_RIGHT, "assets/run.png");
  m_textureRegistry.registerTexture(PLAYER_FALL, "assets/fall.png");
  m_textureRegistry.registerTexture(DIRT, "assets/default_dirt.png");

  myWorld.registerSystem(std::make_unique<RenderSystem>(
      std::make_unique<SdlRenderer>(m_renderer, m_textureRegistry)));
  myWorld.registerSystem(std::make_unique<InputSystem>());

  // DIRT BLOCK
  const auto dirtTextureComponent = std::make_shared<StaticSpriteComponent>(
      DIRT, Rectangle{0, 0, 16.0f, 16.0f});
  const auto dirtPhysicComponent =
      std::make_shared<RigidBodyComponent>(RigidBodyComponentBuilder{}
                                               .withMass(100.0f)
                                               .withCollision()
                                               .withDrag(1.f)
                                               .withoutGravity()
                                               .create());
  myWorld.spawnEntity(ComponentList{dirtTextureComponent, dirtPhysicComponent});

  // KNIGHT
  const auto runTextureComponent = std::make_shared<AnimatedSpriteComponent>(
      PLAYER_RUN_RIGHT, m_animationRegistry.get(PLAYER_RUN_RIGHT), 13);
  const auto fallTextureComponent = std::make_shared<AnimatedSpriteComponent>(
      PLAYER_FALL, m_animationRegistry.get(PLAYER_FALL), 13);
  const auto rigidBodyComponent =
      std::make_shared<RigidBodyComponent>(RigidBodyComponentBuilder{}
                                               .withMass(100.0f)
                                               .withCollision()
                                               .withGravity()
                                               .withDrag(0.f)
                                               .create());
  const auto inputComponent = std::make_shared<InputComponent>();

  const auto transformComponent = std::make_shared<TransformComponent>();

  myWorld.spawnEntity(ComponentList{rigidBodyComponent, transformComponent,
                                    runTextureComponent, inputComponent});

  Uint64 NOW = SDL_GetPerformanceCounter();
  Uint64 LAST = 0;
  float deltaTime = 0;

  while (!m_exit) {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();

    deltaTime = static_cast<float>(NOW - LAST) * 1000 /
                static_cast<float>(SDL_GetPerformanceFrequency());

    std::cout << "Up? " << inputComponent->hasFlag(InputFlags::Up) << std::endl;

    // Process events
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        m_exit = true;
      }

      if (e.type == SDL_EVENT_KEY_DOWN) {
        if (e.key.key == SDLK_RIGHT) {
          inputComponent->enableFlag(InputFlags::Right);
        }

        if (e.key.key == SDLK_LEFT) {
          inputComponent->enableFlag(InputFlags::Left);
        }

        if (e.key.key == SDLK_UP) {
          inputComponent->enableFlag(InputFlags::Up);
        }
      }

      if (e.type == SDL_EVENT_KEY_UP) {
        if (e.key.key == SDLK_RIGHT) {
          inputComponent->disableFlag(InputFlags::Right);
        }

        if (e.key.key == SDLK_LEFT) {
          inputComponent->disableFlag(InputFlags::Left);
        }

        if (e.key.key == SDLK_UP) {
          inputComponent->disableFlag(InputFlags::Up);
        }
      }
    }

    // Now that events are processed, render screen
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(m_renderer);

    // Call systems to update our world
    myWorld.update(deltaTime / 1000.0f);

    // Update screen
    SDL_RenderPresent(m_renderer);
    SDL_Delay(16);
  }
}