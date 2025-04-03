#include <SDL3_image/SDL_image.h>

#include "surface_registry.hpp"

void surface_registry::register_surface(surface_id id, std::string path) {
  // Load the surface from the given path and store it in the m_textures map
  SDL_Surface* surface = IMG_Load(path.c_str());

  if (surface == nullptr) {
    SDL_Log("Failed to load surface: %s", SDL_GetError());
  }

  m_surfaces.emplace(id, surface);
}