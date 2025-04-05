#ifndef GAME_HPP
#define GAME_HPP
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include "animation_registry.hpp"
#include "sdl/sdl_texture_registry.hpp"

namespace mth {
class Game {
 public:
  Game();
  ~Game();

  void exit() const;

  void loop();

 private:
  SDL_Window* m_window{nullptr};
  SDL_Renderer* m_renderer{nullptr};
  bool m_exit{false};
  SdlTextureRegistry m_textureRegistry{nullptr};
  AnimationRegistry m_animationRegistry{};
};
}  // namespace mth

#endif  // GAME_HPP
