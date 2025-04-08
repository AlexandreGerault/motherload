#include "physic_system.hpp"

#include <ranges>

#include "../components/component.hpp"
#include "../components/rigid_body_component.hpp"
#include "../components/transform_component.hpp"
#include "../constants.hpp"
#include "../world.hpp"

using namespace mth;
using mth::components::TransformComponent;

void PhysicSystem::update(World &world, const float dt) {
  const auto rigid_bodies = world.havingComponents(RigidBody | Transform);

  for (const auto &components : rigid_bodies | std::views::values) {
    auto rigidBodyIterator =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<RigidBodyComponent>(component) !=
                 nullptr;
        });

    auto transformIterator =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<TransformComponent>(component) !=
                 nullptr;
        });

    if (rigidBodyIterator == components.end() ||
        transformIterator == components.end()) {
      continue;
    }

    // Cast the component to position type
    const auto transformComponent =
        std::dynamic_pointer_cast<TransformComponent>(*rigidBodyIterator);

    transformComponent->position.x += transformComponent->velocity.x * dt;

    transformComponent->velocity.y +=
        mth::constants::PIXEL_BY_METER * mth::constants::GRAVITY * dt;
    transformComponent->position.y += transformComponent->velocity.y * dt;

    if (transformComponent->position.y > 600.0f) {
      transformComponent->position.y = 600.0f;
      transformComponent->velocity.y = 0;
    }
  }
}
