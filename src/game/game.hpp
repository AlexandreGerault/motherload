#ifndef GAME_HPP
#define GAME_HPP
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include "sdl/sdl_texture_registry.hpp"

namespace mth {
class Game {
 public:
  Game();
  ~Game();

  void exit() const;

  void loop();

 private:
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
  bool m_exit;
  SdlTextureRegistry m_textureRegistry;
};
}  // namespace mth

#endif  // GAME_HPP
