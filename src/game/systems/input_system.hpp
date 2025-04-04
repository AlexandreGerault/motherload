#ifndef INPUT_SYSTEM_HPP
#define INPUT_SYSTEM_HPP
#include "system.hpp"

namespace mth {
class InputSystem final : public System {
 public:
  InputSystem() = default;

  ~InputSystem() override = default;

  void update(World &world, float dt) override;
};
}  // namespace mth

#endif  // INPUT_SYSTEM_HPP
