#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP
#include <SDL3/SDL_render.h>

#include "system.hpp"

namespace mth {
class RenderSystem : public System {
 public:
  RenderSystem() = delete;
  explicit RenderSystem(SDL_Renderer *renderer);

  void update(World &world, float dt) override;

 private:
  SDL_Renderer *m_renderer;
};
}  // namespace mth

#endif  // RENDER_SYSTEM_HPP
