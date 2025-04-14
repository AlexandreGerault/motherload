#include <cstdint>

#include "component.hpp"

namespace mth::components {
enum class InputFlags {
  Up = 1 << 0,
  Down = 1 << 1,
  Left = 1 << 2,
  Right = 1 << 3,
  Jump = 1 << 4,
  Attack = 1 << 5,
  Interact = 1 << 6
};

struct InputComponent final : Component {
  uint8_t flags{0};

  InputComponent() = default;

  bool hasFlag(InputFlags flag) const;

  void toggleFlag(InputFlags flag);

  void enableFlag(InputFlags flag);

  void disableFlag(InputFlags flag);

  ComponentTypes type() override;
};
}  // namespace mth::components