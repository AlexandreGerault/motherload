#ifndef RENDERER_HPP
#define RENDERER_HPP
#include "maths/rectangle.hpp"
#include "textures.hpp"

namespace mth {
using namespace math;
class Renderer {
 public:
  virtual ~Renderer() = default;
  virtual void render(TextureId texture, Rectangle destination,
                      Rectangle clip) = 0;
};
}  // namespace mth

#endif  // RENDERER_HPP
