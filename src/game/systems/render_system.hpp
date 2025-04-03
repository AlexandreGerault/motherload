#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP
#include <SDL3/SDL_render.h>

#include "system.hpp"

namespace game {
class render_system : public system {
 public:
  render_system() = delete;
  explicit render_system(SDL_Renderer *renderer);

  void update(world &world, float dt) override;

 private:
  SDL_Renderer *m_renderer;
};
}  // namespace game

#endif  // RENDER_SYSTEM_HPP
