#ifndef SDL_RENDERER_HPP
#define SDL_RENDERER_HPP
#include <SDL3/SDL_render.h>

#include "../renderer.hpp"
#include "sdl_texture_registry.hpp"

namespace mth {
class SdlRenderer final : public Renderer {
 public:
  explicit SdlRenderer(SDL_Renderer* renderer,
                       SdlTextureRegistry& textureRegistry);
  ~SdlRenderer() override = default;

  void render(TextureId surfaceId, float x, float y, float w, float h) override;

 private:
  SDL_Renderer* m_renderer;
  SdlTextureRegistry& m_textureRegistry;
};
}  // namespace mth

#endif  // SDL_RENDERER_HPP
