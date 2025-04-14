#include "animation_registry.hpp"

using namespace mth;
using namespace mth::math;

AnimationRegistry::AnimationRegistry() {
  m_animations.emplace(PLAYER_RUN_RIGHT,
                       std::vector{Rectangle{40.f, 40.f, 35.0f, 40.0f},
                                   Rectangle{160.f, 40.f, 30.0f, 40.0f},
                                   Rectangle{285.0f, 40.f, 30.0f, 40.0f},
                                   Rectangle{404.f, 40.f, 20.0f, 40.0f}});

  m_animations.emplace(PLAYER_FALL, std::vector{
                                        Rectangle{39.f, 42.f, 29.0f, 39.0f},
                                        Rectangle{159.f, 42.f, 29.0f, 39.0f},
                                        Rectangle{279.f, 42.f, 29.0f, 39.0f},
                                    });
}

std::vector<math::Rectangle> AnimationRegistry::get(TextureId textureId) {
  return m_animations.at(textureId);
}
