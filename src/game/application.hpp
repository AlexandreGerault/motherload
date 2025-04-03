#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>

#include <memory>

class application {
 public:
  bool m_exit;

  application();

  void exit() const;

  void loop();

 private:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
  std::unique_ptr<SDL_Surface, decltype(&SDL_DestroySurface)> m_screen_surface;
};

#endif  // APPLICATION_HPP
