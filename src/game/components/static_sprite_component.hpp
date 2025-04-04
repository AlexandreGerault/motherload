#ifndef TEXTURE_COMPONENT_HPP
#define TEXTURE_COMPONENT_HPP

#include "../maths/rectangle.hpp"
#include "../textures.hpp"
#include "component.hpp"

namespace mth {
using namespace math;

struct StaticSpriteComponent final : Component {
  StaticSpriteComponent() = delete;
  explicit StaticSpriteComponent(TextureId m_textureId, Rectangle clip);
  ComponentTypes type() override;

  TextureId m_textureId;
  Rectangle m_clip;
};
}  // namespace mth

#endif  // TEXTURE_COMPONENT_HPP
