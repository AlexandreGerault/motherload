#include "render_system.hpp"

#include <ranges>

#include "../components/animated_sprite_component.hpp"
#include "../components/static_sprite_component.hpp"
#include "../components/transform_component.hpp"
#include "../world.hpp"

using namespace mth;
using namespace components;
using components::AnimatedSpriteComponent;
using components::StaticSpriteComponent;
using components::TransformComponent;

RenderSystem::RenderSystem(std::unique_ptr<Renderer> renderer)
    : m_renderer{std::move(renderer)} {}

void RenderSystem::update(World &world, const float dt) {
  const auto staticSpriteEntities =
      world.havingComponents(Transform | StaticSprite);

  for (const auto &components : staticSpriteEntities | std::views::values) {
    auto transformIt =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<TransformComponent>(component) !=
                 nullptr;
        });

    auto textureIt =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<StaticSpriteComponent>(component) !=
                 nullptr;
        });

    if (transformIt == components.end() || textureIt == components.end()) {
      continue;
    }

    // Cast the component to position type
    const auto transformComponent =
        std::dynamic_pointer_cast<TransformComponent>(*transformIt);
    const auto textureComponent =
        std::dynamic_pointer_cast<StaticSpriteComponent>(*textureIt);

    m_renderer->render(textureComponent->m_textureId,
                       Rectangle{transformComponent->position.x,
                                 transformComponent->position.y,
                                 textureComponent->m_clip.width,
                                 textureComponent->m_clip.height},
                       textureComponent->m_clip);
  }

  const auto animatedSpriteEntities =
      world.havingComponents(Transform | AnimatedSprite);

  for (const auto &components : animatedSpriteEntities | std::views::values) {
    auto transformIt =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<TransformComponent>(component) !=
                 nullptr;
        });

    auto textureIt =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<AnimatedSpriteComponent>(
                     component) != nullptr;
        });

    if (transformIt == components.end() || textureIt == components.end()) {
      continue;
    }

    // Cast the component to position type
    const auto transformComponent =
        std::dynamic_pointer_cast<TransformComponent>(*transformIt);
    const auto textureComponent =
        std::dynamic_pointer_cast<AnimatedSpriteComponent>(*textureIt);

    const Rectangle currentClip = textureComponent->getCurrentClip();

    m_renderer->render(textureComponent->textureId,
                       Rectangle{transformComponent->position.x,
                                 transformComponent->position.y,
                                 currentClip.width, currentClip.height},
                       currentClip);

    textureComponent->addTime(dt);
  }
}
