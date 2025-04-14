#include "animated_sprite_component.hpp"

#include <utility>

using namespace mth::components;

AnimatedSpriteComponent::AnimatedSpriteComponent(const TextureId textureId,
                                                 std::vector<Rectangle> clips,
                                                 const int framerate)
    : framerate(framerate), textureId{textureId}, clips{std::move(clips)} {}

ComponentTypes AnimatedSpriteComponent::type() { return AnimatedSprite; }

int AnimatedSpriteComponent::currentFrameIndex() const {
  return static_cast<int>(elapsedTime * static_cast<float>(framerate)) %
         static_cast<int>(clips.size());
}

Rectangle AnimatedSpriteComponent::getCurrentClip() const {
  return clips.at(currentFrameIndex());
}

void AnimatedSpriteComponent::addTime(const float dt) {
  elapsedTime += dt;

  if (currentFrameIndex() == clips.size() - 1) {
    elapsedTime = 0;
  }
}
