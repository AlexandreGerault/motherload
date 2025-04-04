#include "sdl_renderer.hpp"

#include <SDL3/SDL_log.h>

#include <memory>

mth::SdlRenderer::SdlRenderer(SDL_Renderer* renderer,
                              SdlTextureRegistry& textureRegistry)
    : m_renderer(renderer), m_textureRegistry(textureRegistry) {}

void mth::SdlRenderer::render(const TextureId surfaceId,
                              const Rectangle destination,
                              const Rectangle clip) {
  const auto texture = m_textureRegistry.get(surfaceId);

  if (!texture) {
    SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
  }

  const SDL_FRect dstRect = {destination.x, destination.y, destination.width,
                             destination.height};
  const SDL_FRect clipRect = {clip.x, clip.y, clip.width, clip.height};

  SDL_RenderTexture(m_renderer, texture, &clipRect, &dstRect);
}