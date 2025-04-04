#ifndef SDL_RENDERER_HPP
#define SDL_RENDERER_HPP
#include <SDL3/SDL_render.h>

#include "renderer.hpp"

namespace mth {
class SdlRenderer final : public Renderer {
 public:
  explicit SdlRenderer(SDL_Renderer* renderer);
  ~SdlRenderer() override;

  void render(TextureId surfaceId, float x, float y, float w, float h) override;

 private:
  SDL_Renderer* m_renderer;
};
}  // namespace mth

#endif  // SDL_RENDERER_HPP
