#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "textures.hpp"

namespace mth {
class Renderer {
 public:
  virtual ~Renderer() = default;
  virtual void render(TextureId texture, float x, float y, float width,
                      float height) = 0;
};
}  // namespace mth

#endif  // RENDERER_HPP
