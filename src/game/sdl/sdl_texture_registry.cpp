#include "sdl_texture_registry.hpp"

#include <SDL3_image/SDL_image.h>

#include "../textures.hpp"

SdlTextureRegistry::SdlTextureRegistry(SDL_Renderer* renderer)
    : m_renderer(renderer) {}

SdlTextureRegistry::~SdlTextureRegistry() {
  for (auto [id, texture] : m_textures) {
    SDL_DestroyTexture(texture);
  }

  m_textures.clear();
}

void SdlTextureRegistry::registerTexture(const TextureId id,
                                         const std::string& path) {
  // Load the surface from the given path and store it in the m_textures map
  SDL_Surface* surface = IMG_Load(path.c_str());

  if (surface == nullptr) {
    SDL_Log("Failed to load surface: %s", SDL_GetError());
  }

  SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);

  if (texture == nullptr) {
    SDL_Log("Failed to create texture: %s", SDL_GetError());
  }

  m_textures[id] = texture;
}

SDL_Texture* SdlTextureRegistry::get(const TextureId id) {
  auto it = m_textures.find(id);

  if (it != m_textures.end()) {
    return it->second;
  }

  SDL_Log("Texture not found for ID: %d", id);
  throw std::runtime_error("Texture not found");
}