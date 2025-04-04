#include "render_system.hpp"

#include <SDL3/SDL_log.h>

#include <iostream>
#include <ostream>
#include <ranges>

#include "../components/physic_component.hpp"
#include "../components/texture_component.hpp"
#include "../world.hpp"

using namespace mth;

RenderSystem::RenderSystem(std::unique_ptr<Renderer> renderer)
    : m_renderer{std::move(renderer)} {}

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
          return std::dynamic_pointer_cast<StaticSpriteComponent>(component) !=
                 nullptr;
        });

    if (physic_it == components.end() || texture_it == components.end()) {
      continue;
    }

    // Cast the component to position type
    const auto pos_component =
        std::dynamic_pointer_cast<PhysicComponent>(*physic_it);
    const auto texture_component =
        std::dynamic_pointer_cast<StaticSpriteComponent>(*texture_it);

    m_renderer->render(
        texture_component->m_textureId,
        Rectangle{pos_component->x, pos_component->y,
                  texture_component->m_clip.width, texture_component->m_clip.height},
        texture_component->m_clip);
  }
}
