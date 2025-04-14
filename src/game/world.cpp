#include "world.hpp"

#include <ostream>

#include "systems/physic_system.hpp"

using namespace mth;
using components::ComponentList;

World::World() { registerSystem(std::make_unique<PhysicSystem>()); }

void World::registerSystem(std::unique_ptr<System> system) {
  m_systems.push_back(std::move(system));
}

void World::spawnEntity(ComponentList &&components) {
  const Entity new_entity = m_entityFactory.create();

  m_components.insert({new_entity, std::move(components)});
}

void World::killEntity(const Entity entity) { m_components.erase(entity); }

void World::update(const float dt) {
  for (const auto &_s : m_systems) {
    _s->update(*this, dt);
  }
}

std::unordered_map<Entity, ComponentList> World::havingComponents(int flags) {
  std::unordered_map<Entity, ComponentList> result;

  for (const auto &[entity_id, components] : m_components) {
    int found_flags = 0;

    for (const auto &component : components) {
      found_flags |= component->type();
    }

    if ((found_flags & flags) == flags) {
      result[entity_id] = components;
    }
  }

  return result;
}

Entity EntityFactory::create() { return m_last++; }
