#ifndef ANIMATED_SPRITE_COMPONENT_HPP
#define ANIMATED_SPRITE_COMPONENT_HPP
#include <vector>

#include "../maths/rectangle.hpp"
#include "../textures.hpp"
#include "component.hpp"

namespace mth {
struct AnimatedSpriteComponent final : Component {
  ComponentTypes type() override;
  explicit AnimatedSpriteComponent(TextureId textureId,
                                   std::vector<math::Rectangle> clips,
                                   int framerate);

  float elapsedTime{0};
  int framerate{};
  TextureId textureId;
  std::vector<math::Rectangle> clips{};
};
}  // namespace mth

#endif  // ANIMATED_SPRITE_COMPONENT_HPP
