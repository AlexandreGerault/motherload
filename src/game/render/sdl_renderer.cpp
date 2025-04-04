#include "sdl_renderer.hpp"

#include <SDL3/SDL_log.h>

#include <memory>

mth::SdlRenderer::SdlRenderer(SDL_Renderer* renderer) : m_renderer(renderer) {}

void mth::SdlRenderer::render(TextureId surfaceId, float x, float y, float w,
                              float h) {
  auto texture = m_textureRegistry.get(surfaceId);

  if (!texture) {
    SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
  }

  const SDL_FRect dstRect = {x, y, w, h};
  const SDL_FRect clipRect = {40.0, 40.0, 35.0, 40.0};

  SDL_RenderTexture(m_renderer, texture, &clipRect, &dstRect);
}