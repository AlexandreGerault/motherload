#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H
#include "../maths/vec_2.hpp"
#include "component.hpp"

using mth::math::Vec2;

namespace mth::components {
struct TransformComponent final : Component {
  TransformComponent() = default;

  Vec2 position{0.0f, 0.0f};
  Vec2 velocity{0.0f, 0.0f};
  Vec2 acceleration{0.0f, 0.0f};

  ComponentTypes type() override;
};
}  // namespace mth::components

#endif  // TRANSFORM_COMPONENT_H