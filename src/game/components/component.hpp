#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <SDL3/SDL_surface.h>

#include <memory>
#include <vector>

namespace mth {
enum ComponentTypes {
  Physic = 1 << 0,
  Inventory = 1 << 1,
  Texture = 1 << 2,
};

struct Component {
  virtual ~Component() = default;
  virtual ComponentTypes getComponentType() = 0;
};

struct InventoryComponent final : Component {
  ComponentTypes getComponentType() override { return Inventory; }
};

typedef std::vector<std::shared_ptr<Component>> ComponentList;
}  // namespace mth

#endif  // COMPONENT_HPP
