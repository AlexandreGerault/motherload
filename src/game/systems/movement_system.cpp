#include "movement_system.hpp"
#include <ranges>

#include "../world.hpp"
#include "../components/component.hpp"

using namespace game;

void movement_system::update(world& world, const float dt)
{
    const auto moving_entities_with_inventory = world.having_components(Physic);

    for (const auto& components : moving_entities_with_inventory | std::views::values)
    {
        auto physic_it = std::ranges::find_if(
            components,
            [](const auto& component) { return std::dynamic_pointer_cast<physic>(component) != nullptr; }
        );

        if (physic_it == components.end())
        {
            continue;
        }

        // Cast the component to position type
        const auto pos_component = std::dynamic_pointer_cast<physic>(*physic_it);

        pos_component->x += 1.0f * dt;
        pos_component->y += 1.0f * dt;
    }
}
