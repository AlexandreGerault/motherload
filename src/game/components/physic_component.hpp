#ifndef PHYSIC_COMPONENT_H
#define PHYSIC_COMPONENT_H
#include "component.hpp"

namespace mth {
struct PhysicComponent final : Component {
  float x;
  float y;

  float sx;
  float sy;

  float ax;
  float ay;

  PhysicComponent() = delete;

  PhysicComponent(const float _x, const float _y, const float _sx,
                  const float _sy, const float _ax, const float _ay)
      : x{_x}, y{_y}, sx{_sx}, sy{_sy}, ax{_ax}, ay{_ay} {};

  ComponentTypes getComponentType() override;
};
}  // namespace mth

#endif  // PHYSIC_COMPONENT_H
