#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <cstdlib>

#include "game/game.hpp"

constexpr int kScreenWidth{1920};
constexpr int kScreenHeight{1080};

int main(int argc, char **argv) {
  mth::Game my_game{};

  my_game.loop();

  return EXIT_SUCCESS;
}
