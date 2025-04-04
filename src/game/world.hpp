#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

#include "components/component.hpp"
#include "surface_registry.hpp"
#include "systems/system.hpp"

namespace mth {
typedef uint32_t Entity;

struct EntityFactory {
  Entity m_last;

  EntityFactory() : m_last{0} {}

  Entity create();
};

class World {
 public:
  World();

  void spawnEntity(ComponentList &&components);
  void killEntity(Entity entity);

  void registerSystem(std::unique_ptr<System> system);

  void update(float dt);
  std::unordered_map<Entity, ComponentList> havingComponents(int flags);

  SDL_Surface *getSurface(surface_id id);

 private:
  std::unordered_map<Entity, ComponentList> m_components;
  std::vector<std::unique_ptr<System>> m_systems;
  EntityFactory m_entityFactory;
  SurfaceRegistry m_textureRegistry;
};
}  // namespace mth

#endif  // WORLD_HPP