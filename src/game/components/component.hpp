#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <SDL3/SDL_surface.h>

#include <memory>
#include <vector>

namespace mth {
enum ComponentTypes {
  Physic = 1 << 0,
  Inventory = 1 << 1,
  StaticSprite = 1 << 2,
  AnimatedSprite = 1 << 3,
};

struct Component {
  virtual ~Component() = default;
  virtual ComponentTypes type() = 0;
};

struct InventoryComponent final : Component {
  ComponentTypes type() override { return Inventory; }
};

typedef std::vector<std::shared_ptr<Component>> ComponentList;
}  // namespace mth

#endif  // COMPONENT_HPP
