#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H
#include "../maths/vec_2.hpp"
#include "component.hpp"

using mth::math::Vec2;

namespace mth::components {
struct TransformComponent final : Component {
  Vec2 position;
  Vec2 velocity;
  Vec2 acceleration;

  TransformComponent()
      : position{0.0f, 0.0f}, velocity{0.0f, 0.0f}, acceleration{0.0f, 0.0f} {}

  ComponentTypes type() { return Transform; }
};
}  // namespace mth::components

#endif  // TRANSFORM_COMPONENT_H