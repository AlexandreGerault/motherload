#ifndef ANIMATION_REGISTRY_HPP
#define ANIMATION_REGISTRY_HPP
#include <unordered_map>
#include <vector>

#include "maths/rectangle.hpp"
#include "textures.hpp"

namespace mth {
class AnimationRegistry {
 public:
  AnimationRegistry();
  ~AnimationRegistry() = default;

  std::vector<math::Rectangle> get(TextureId);

 private:
  std::unordered_map<TextureId, std::vector<math::Rectangle>> m_animations;
};
}  // namespace mth

#endif  // ANIMATION_REGISTRY_HPP
