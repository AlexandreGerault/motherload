#include "game.hpp"

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_timer.h>

#include <iostream>

#include "./textures.hpp"
#include "components/animated_sprite_component.hpp"
#include "components/physic_component.hpp"
#include "components/static_sprite_component.hpp"
#include "sdl/sdl_renderer.hpp"
#include "systems/input_system.hpp"
#include "systems/render_system.hpp"
#include "world.hpp"

using namespace mth;

Game::Game() {
  SDL_CreateWindowAndRenderer("SDL3 Tutorial", 860, 640, SDL_WINDOW_MAXIMIZED,
                              &m_window, &m_renderer);

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

  World my_world{};

  m_textureRegistry.registerTexture(PLAYER_RUN, "assets/run.png");
  m_textureRegistry.registerTexture(PLAYER_FALL, "assets/fall.png");
  m_textureRegistry.registerTexture(DIRT, "assets/default_dirt.png");

  my_world.registerSystem(std::make_unique<RenderSystem>(
      std::make_unique<SdlRenderer>(m_renderer, m_textureRegistry)));
  my_world.registerSystem(std::make_unique<InputSystem>());

  ComponentList components{};

  // DIRT BLOCK
  const auto dirt_texture_component = std::make_shared<StaticSpriteComponent>(
      DIRT, Rectangle{0, 0, 16.0f, 16.0f});
  const auto dirt_physic_component =
      std::make_shared<PhysicComponent>(100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

  // KNIGHT
  const auto texture_component = std::make_shared<AnimatedSpriteComponent>(
      PLAYER_RUN, m_animationRegistry.get(PLAYER_RUN), 13);
  const auto fall_texture_component = std::make_shared<AnimatedSpriteComponent>(
      PLAYER_FALL, m_animationRegistry.get(PLAYER_FALL), 13);
  const auto physic_component =
      std::make_shared<PhysicComponent>(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

  components.push_back(physic_component);
  components.push_back(texture_component);

  my_world.spawnEntity(ComponentList{physic_component, fall_texture_component});

  my_world.spawnEntity(
      ComponentList{dirt_texture_component, dirt_physic_component});

  Uint64 NOW = SDL_GetPerformanceCounter();
  Uint64 LAST = 0;
  float deltaTime = 0;

  while (!m_exit) {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();

    deltaTime = static_cast<float>(NOW - LAST) * 1000 /
                static_cast<float>(SDL_GetPerformanceFrequency());

    // Process events
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        m_exit = true;
      }
    }

    // Now that events are processed, render screen
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(m_renderer);

    // Call systems to update our world
    my_world.update(deltaTime / 1000.0f);

    // Update screen
    SDL_RenderPresent(m_renderer);
    SDL_Delay(16);
  }
}