#include "surface_registry.hpp"

#include <SDL3_image/SDL_image.h>

SurfaceRegistry::~SurfaceRegistry() {
  for (auto& [key, value] : m_surfaces) {
    SDL_DestroySurface(value);
  }
}

void SurfaceRegistry::registerSurface(surface_id id, const std::string& path) {
  // Load the surface from the given path and store it in the m_textures map
  SDL_Surface* surface = IMG_Load(path.c_str());

  if (surface == nullptr) {
    SDL_Log("Failed to load surface: %s", SDL_GetError());
  }

  m_surfaces.emplace(id, surface);
}

SDL_Surface* SurfaceRegistry::getSurface(const surface_id id) {
  auto it = m_surfaces.find(id);

  if (it != m_surfaces.end()) {
    return it->second;
  }

  SDL_Log("Surface not found for ID: %d", id);
  throw std::runtime_error("Surface not found");
}