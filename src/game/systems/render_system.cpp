#include "render_system.hpp"

#include <iostream>
#include <ostream>
#include <ranges>

#include "../components/animated_sprite_component.hpp"
#include "../components/rigid_body_component.hpp"
#include "../components/static_sprite_component.hpp"
#include "../world.hpp"

using namespace mth;

struct StaticSpriteComponent;

RenderSystem::RenderSystem(std::unique_ptr<Renderer> renderer)
    : m_renderer{std::move(renderer)} {}

void RenderSystem::update(World &world, float dt) {
  const auto static_sprite_entities =
      world.havingComponents(RigidBody | StaticSprite);

  for (const auto &components : static_sprite_entities | std::views::values) {
    auto physic_it =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<RigidBodyComponent>(component) !=
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
        std::dynamic_pointer_cast<RigidBodyComponent>(*physic_it);
    const auto texture_component =
        std::dynamic_pointer_cast<StaticSpriteComponent>(*texture_it);

    m_renderer->render(texture_component->m_textureId,
                       Rectangle{pos_component->x, pos_component->y,
                                 texture_component->m_clip.width,
                                 texture_component->m_clip.height},
                       texture_component->m_clip);
  }

  const auto animated_sprite_entities =
      world.havingComponents(RigidBody | AnimatedSprite);

  for (const auto &components : animated_sprite_entities | std::views::values) {
    auto physic_it =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<RigidBodyComponent>(component) !=
                 nullptr;
        });

    auto texture_it =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<AnimatedSpriteComponent>(
                     component) != nullptr;
        });

    if (physic_it == components.end() || texture_it == components.end()) {
      continue;
    }

    // Cast the component to position type
    const auto pos_component =
        std::dynamic_pointer_cast<RigidBodyComponent>(*physic_it);
    const auto texture_component =
        std::dynamic_pointer_cast<AnimatedSpriteComponent>(*texture_it);

    const Rectangle currentClip = texture_component->getCurrentClip();

    m_renderer->render(texture_component->textureId,
                       Rectangle{pos_component->x, pos_component->y,
                                 currentClip.width, currentClip.height},
                       currentClip);

    texture_component->addTime(dt);
  }
}
