#include "physic_system.hpp"

#include <ranges>

#include "../components/component.hpp"
#include "../components/input_component.hpp"
#include "../components/rigid_body_component.hpp"
#include "../components/transform_component.hpp"
#include "../constants.hpp"
#include "../world.hpp"

using namespace mth;
using namespace mth::components;
using components::TransformComponent;

void PhysicSystem::update(World &world, const float dt) {
  const auto physicObjects = world.havingComponents(Transform | RigidBody);

  for (const auto &components : physicObjects | std::views::values) {
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

    auto inputComponentIterator =
        std::ranges::find_if(components, [](const auto &component) {
          return std::dynamic_pointer_cast<InputComponent>(component) !=
                 nullptr;
        });

    if (rigidBodyIterator == components.end() ||
        transformIterator == components.end()) {
      continue;
    }

    // Cast the component to position type
    const auto transformComponent =
        std::dynamic_pointer_cast<TransformComponent>(*transformIterator);

    const auto rigidBodyComponent =
        std::dynamic_pointer_cast<RigidBodyComponent>(*rigidBodyIterator);

    const auto inputComponent =
        std::dynamic_pointer_cast<InputComponent>(*inputComponentIterator);

    const math::Vec2 up{0.0f, inputComponent == nullptr ? 0.0f
                              : inputComponent->hasFlag(InputFlags::Up)
                                  ? -2000.0f
                                  : 0.0f};

    const math::Vec2 weight =
        math::Vec2{0.0f, rigidBodyComponent->useGravity ? 1.0f : 0.0f} *
        rigidBodyComponent->mass * constants::GRAVITY;

    const math::Vec2 friction =
        Vec2{-transformComponent->velocity.x, -transformComponent->velocity.y} *
        transformComponent->velocity.y * transformComponent->velocity.y *
        rigidBodyComponent->drag;

    if (inputComponent != nullptr) {
      if (inputComponent->hasFlag(InputFlags::Right)) {
        transformComponent->velocity.x += 1000.0f * dt;
      }

      if (inputComponent->hasFlag(InputFlags::Left)) {
        transformComponent->velocity.x -= 1000.0f * dt;
      }
    }

    const math::Vec2 acceleration = (1 / rigidBodyComponent->mass) *
                                    (weight + friction + up) *
                                    constants::PIXEL_BY_METER;

    transformComponent->velocity += acceleration * dt;

    transformComponent->position += transformComponent->velocity * dt;

    if (transformComponent->position.y > 600.0f) {
      transformComponent->position.y = 600.0f;
      transformComponent->velocity.y = 0.0f;
    }

    if (transformComponent->position.y < 0.0f) {
      transformComponent->position.y = 0.0f;
      transformComponent->velocity.y = -transformComponent->velocity.y;
    }

    if (transformComponent->position.x > 840.0f) {
      transformComponent->position.x = 840.0f;
      transformComponent->velocity.x = -transformComponent->velocity.x;
    }

    if (transformComponent->position.x < 0.0f) {
      transformComponent->position.x = 0.0f;
      transformComponent->velocity.x = -transformComponent->velocity.x;
    }
  }
}
