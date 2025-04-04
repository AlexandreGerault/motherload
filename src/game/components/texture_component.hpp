#ifndef TEXTURE_COMPONENT_HPP
#define TEXTURE_COMPONENT_HPP

#include "component.hpp"

namespace mth {
struct TextureComponent final : Component {
  TextureComponent() = delete;
  explicit TextureComponent(SDL_Surface* surface);
  ComponentTypes getComponentType() override { return Texture; }

  SDL_Surface* m_surface;
};
}

#endif //TEXTURE_COMPONENT_HPP
