#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <SDL3/SDL_surface.h>

#include <memory>
#include <vector>

namespace mth::components {
enum ComponentTypes {
  RigidBody = 1 << 0,
  Transform = 1 << 1,
  Inventory = 1 << 2,
  StaticSprite = 1 << 3,
  AnimatedSprite = 1 << 4,
  Input = 1 << 5,
};

struct Component {
  virtual ~Component() = default;
  virtual ComponentTypes type() = 0;
};

struct InventoryComponent final : Component {
  ComponentTypes type() override { return Inventory; }
};

typedef std::vector<std::shared_ptr<Component>> ComponentList;
}  // namespace mth::components

#endif  // COMPONENT_HPP
