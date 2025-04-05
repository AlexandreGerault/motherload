#include "render_system.hpp"

#include <iostream>
#include <ostream>
#include <ranges>

#include "../components/animated_sprite_component.hpp"
#include "../components/physic_component.hpp"
#include "../components/static_sprite_component.hpp"
#include "../world.hpp"

using namespace mth;

struct StaticSpriteComponent;

RenderSystem::RenderSystem(std::unique_ptr<Renderer> renderer)
    : m_renderer{std::move(renderer)} {}

void RenderSystem::update(World &world, float dt) {
  const auto static_sprite_entities =
      world.havingComponents(Physic | StaticSprite);

  for (const auto &components : static_sprite_entities | std::views::values) {
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

    m_renderer->render(texture_component->m_textureId,
                       Rectangle{pos_component->x, pos_component->y,
                                 texture_component->m_clip.width,
                                 texture_component->m_clip.height},
                       texture_component->m_clip);
  }

  const auto animated_sprite_entities =
      world.havingComponents(Physic | AnimatedSprite);

  for (const auto &components : animated_sprite_entities | std::views::values) {
    auto physic_it =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<PhysicComponent>(component) !=
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
        std::dynamic_pointer_cast<PhysicComponent>(*physic_it);
    const auto texture_component =
        std::dynamic_pointer_cast<AnimatedSpriteComponent>(*texture_it);

    texture_component->elapsedTime += dt;

    std::cout << "1/framerate: "
              << 1.0f / static_cast<float>(texture_component->framerate)
              << "\n";

    const int frame = static_cast<int>((texture_component->elapsedTime) *
                                       texture_component->framerate) %
                      static_cast<int>(texture_component->clips.size());

    std::cout << "Elapsed time: " << texture_component->elapsedTime << "\n";
    std::cout << "Frame: " << frame << "\n";

    const auto currentClip = texture_component->clips[frame];

    m_renderer->render(texture_component->textureId,
                       Rectangle{pos_component->x, pos_component->y,
                                 currentClip.width, currentClip.height},
                       currentClip);
  }
}
