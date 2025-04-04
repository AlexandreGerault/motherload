#include "animated_sprite_component.hpp"

#include <utility>

using namespace mth;

AnimatedSpriteComponent::AnimatedSpriteComponent(
    const TextureId textureId, std::vector<math::Rectangle> clips,
    const int framerate)
    : framerate(framerate), textureId{textureId}, clips{std::move(clips)} {}

ComponentTypes AnimatedSpriteComponent::type() { return AnimatedSprite; }
