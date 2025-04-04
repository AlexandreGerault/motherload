#ifndef TEXTURE_REGISTRY_HPP
#define TEXTURE_REGISTRY_HPP

#include <SDL3/SDL_render.h>

#include <string>
#include <unordered_map>

#include "../textures.hpp"

class SdlTextureRegistry {
 public:
  explicit SdlTextureRegistry(SDL_Renderer* renderer);
  ~SdlTextureRegistry() = default;

  void registerTexture(TextureId, const std::string& path);
  SDL_Texture* get(TextureId id);

 private:
  SDL_Renderer* m_renderer;
  std::unordered_map<TextureId, SDL_Texture*> m_textures{};
};

#endif  // TEXTURE_REGISTRY_HPP
