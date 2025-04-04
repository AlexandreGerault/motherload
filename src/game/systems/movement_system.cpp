#include "movement_system.hpp"

#include <ranges>

#include "../components/component.hpp"
#include "../components/physic_component.hpp"
#include "../world.hpp"

using namespace mth;

void MovementSystem::update(World &world, const float dt) {
  const auto moving_entities_with_inventory = world.havingComponents(Physic);

  for (const auto &components :
       moving_entities_with_inventory | std::views::values) {
    auto physic_it =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<PhysicComponent>(component) !=
                 nullptr;
        });

    if (physic_it == components.end()) {
      continue;
    }

    // Cast the component to position type
    const auto pos_component =
        std::dynamic_pointer_cast<PhysicComponent>(*physic_it);

    pos_component->x += 0.0f * dt;

    pos_component->sy += 40.0f * 9.81 * dt;
    pos_component->y += pos_component->sy * dt;

    if (pos_component->y > 600.0f) {
      pos_component->y = 600.0f;
      pos_component->sy = 0;
    }
  }
}
