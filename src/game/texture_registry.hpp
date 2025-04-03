#ifndef TEXTURE_REGISTRY_HPP
#define TEXTURE_REGISTRY_HPP

#include <unordered_map>
#include <SDL3/SDL_render.h>

const enum texture_id {
    PLAYER = "player",
};

class texture_registry {
  public:
    void register_texture() {}

   private:
     std::unordered_map<texture_id, SDL_Texture*> m_textures{};
};

#endif //TEXTURE_REGISTRY_HPP
