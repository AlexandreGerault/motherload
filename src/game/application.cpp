
#include "application.hpp"

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_timer.h>

#include <chrono>
#include <iostream>

#include "world.hpp"

application::application()
    : m_exit{false},
      m_window{nullptr, SDL_DestroyWindow},
      m_screen_surface{nullptr, SDL_DestroySurface} {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Could not initialize SDL_INIT_VIDEO! SDL error: %s",
            SDL_GetError());
  }

  m_window.reset(SDL_CreateWindow("SDL3 Tutorial", 1920, 1080, 0));

  if (!m_window) {
    SDL_Log("Could not create window. SDL error: %s", SDL_GetError());
  }

  m_screen_surface.reset(SDL_GetWindowSurface(m_window.get()));
}

void application::exit() const {
  SDL_DestroyWindow(m_window.get());

  SDL_Quit();
}

void application::loop() {
  SDL_Event e;
  SDL_zero(e);

  game::world my_world{};

  game::component_list components{};
  components.push_back(
      std::make_shared<game::physic>(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f));

  my_world.spawn_entity(std::move(components));

  Uint64 NOW = SDL_GetPerformanceCounter();
  Uint64 LAST = 0;
  float deltaTime = 0;

  while (!m_exit) {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();

    deltaTime = static_cast<float>(NOW - LAST) * 1000 /
                static_cast<float>(SDL_GetPerformanceFrequency());

    std::cout << "dt in ns: " << deltaTime << "\n";

    // Process events
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        m_exit = true;
      }
    }

    // Call systems to update our world
    my_world.update(deltaTime / 1000.0f);

    // Now that events are processed, render screen
    SDL_FillSurfaceRect(
        m_screen_surface.get(), nullptr,
        SDL_MapSurfaceRGB(m_screen_surface.get(), 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(m_window.get());
  }

  exit();
}