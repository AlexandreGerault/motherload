#include "render_system.hpp"

#include <SDL3/SDL_log.h>

#include <iostream>
#include <ostream>
#include <ranges>

#include "../components/physic_component.hpp"
#include "../components/texture_component.hpp"
#include "../world.hpp"

using namespace mth;

RenderSystem::RenderSystem(SDL_Renderer *renderer) : m_renderer(renderer) {}

void RenderSystem::update(World &world, float dt) {
  const auto entities = world.havingComponents(Physic | Texture);

  for (const auto &components : entities | std::views::values) {
    auto physic_it =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<PhysicComponent>(component) !=
                 nullptr;
        });

    auto texture_it =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<TextureComponent>(component) !=
                 nullptr;
        });

    if (physic_it == components.end() || texture_it == components.end()) {
      continue;
    }

    // Cast the component to position type
    const auto pos_component =
        std::dynamic_pointer_cast<PhysicComponent>(*physic_it);
    const auto texture_component =
        std::dynamic_pointer_cast<TextureComponent>(*texture_it);

    SDL_Texture *texture{
        SDL_CreateTextureFromSurface(m_renderer, texture_component->m_surface)};

    if (!texture) {
      SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
    }

    SDL_FRect dstRect = {0, pos_component->y, 35.0, 40.0};
    SDL_FRect clipRect = {40.0, 40.0, 35.0, 40.0};
    SDL_RenderTexture(m_renderer, texture, &clipRect, &dstRect);

    SDL_DestroyTexture(texture);

    std::cout << "y: " << pos_component->y << "sy= " << pos_component->sy
              << "\n";
  }
}
