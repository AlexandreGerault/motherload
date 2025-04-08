#ifndef PHYSIC_SYSTEM_HPP
#define PHYSIC_SYSTEM_HPP
#include "system.hpp"

namespace mth {
class PhysicSystem final : public System {
 public:
  PhysicSystem() = default;
  ~PhysicSystem() override = default;

  void update(World &world, float dt) override;
};
}  // namespace mth

#endif  // PHYSIC_SYSTEM_HPP
