#include "world.hpp"

#include <ostream>

#include "systems/movement_system.hpp"

using namespace game;

world::world()
{
    register_system(std::make_unique<movement_system>());
}

void world::register_system(std::unique_ptr<system> system)
{
    m_systems.push_back(std::move(system));
}

void world::remove_system(const system* system)
{
    const auto it = std::ranges::find_if(
        m_systems,
        [system](const auto& s) { return s.get() == system; }
    );

    if (it != m_systems.end())
    {
        m_systems.erase(it);
    }
}

void world::spawn_entity(component_list&& components)
{
    const entity new_entity = m_entity_factory.create();

    m_components.insert({new_entity, std::move(components)});
}

void world::kill_entity(const entity entity)
{
    m_components.erase(entity);
}

void world::update(const float dt)
{
    for (const auto& _s : m_systems)
    {
        _s->update(*this, dt);
    }
}

std::unordered_map<entity, component_list> world::having_components(int flags)
{
    std::unordered_map<entity, component_list> result;

    for (const auto& [entity_id, components] : m_components)
    {
        int found_flags = 0;

        for (const auto& component : components)
        {
            found_flags |= component->get_component_type();
        }

        if ((found_flags & flags) == flags)
        {
            result[entity_id] = components;
        }
    }

    return result;
}


entity entity_factory::create()
{
    return m_last++;
}
