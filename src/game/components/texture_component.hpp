#ifndef TEXTURE_COMPONENT_HPP
#define TEXTURE_COMPONENT_HPP

#include <SDL3/SDL_render.h>

#include "../textures.hpp"
#include "component.hpp"

namespace mth {
struct TextureComponent final : Component {
  TextureComponent() = delete;
  explicit TextureComponent(TextureId m_textureId);
  ComponentTypes texture() override { return Texture; }

  TextureId m_textureId;
};
}  // namespace mth

#endif  // TEXTURE_COMPONENT_HPP
