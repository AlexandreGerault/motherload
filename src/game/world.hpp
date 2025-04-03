#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

#include "components/component.hpp"
#include "surface_registry.hpp"
#include "systems/system.hpp"

namespace game {
typedef uint32_t entity;

struct entity_factory {
  entity m_last;

  entity_factory() : m_last{0} {}

  entity create();
};

class world {
 public:
  world();

  void spawn_entity(component_list &&components);
  void kill_entity(entity entity);

  void register_system(std::unique_ptr<system> system);
  void remove_system(const system *system);

  void update(float dt);
  std::unordered_map<entity, component_list> having_components(int flags);

 private:
  std::unordered_map<entity, component_list> m_components;
  std::vector<std::unique_ptr<system>> m_systems;
  entity_factory m_entity_factory;
  surface_registry m_texture_registry;
};
}  // namespace game

#endif  // WORLD_HPP