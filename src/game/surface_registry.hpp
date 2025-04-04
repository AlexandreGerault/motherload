#ifndef TEXTURE_REGISTRY_HPP
#define TEXTURE_REGISTRY_HPP

#include <SDL3/SDL_render.h>

#include <string>
#include <unordered_map>

enum surface_id {
  PLAYER_CROUCH_WALK,
};

class SurfaceRegistry {
 public:
  ~SurfaceRegistry();
  void registerSurface(surface_id, const std::string& path);
  SDL_Surface* getSurface(surface_id id);

 private:
  std::unordered_map<surface_id, SDL_Surface*> m_surfaces{};
};

#endif  // TEXTURE_REGISTRY_HPP
