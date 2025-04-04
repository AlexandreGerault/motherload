#ifndef MOVEMENT_SYSTEM_HPP
#define MOVEMENT_SYSTEM_HPP
#include "system.hpp"

namespace mth {
class MovementSystem final : public System {
 public:
  MovementSystem() = default;
  ~MovementSystem() override = default;

  void update(World &world, float dt) override;
};
}  // namespace mth

#endif  // MOVEMENT_SYSTEM_HPP
