#include "../src/game/world.hpp"

#include <catch2/catch_test_macros.hpp>

#include "../src/game/components/rigid_body_component.hpp"

using namespace mth::components;
TEST_CASE("A system can require the entities having a set of components",
          "[world]") {
  auto rigidBodyComponentBuilder = RigidBodyComponentBuilder{}
                                       .withMass(100.0f)
                                       .withCollision()
                                       .withDrag(1.f)
                                       .withoutGravity();

  SECTION("Fetching entity with only one component") {
    mth::World world;

    world.spawnEntity({std::make_unique<RigidBodyComponent>(
        rigidBodyComponentBuilder.create())});
    world.spawnEntity({std::make_unique<InventoryComponent>()});

    const auto physic_entities =
        world.havingComponents(RigidBody);
    const auto first_matching_entity = physic_entities.at(0);

    REQUIRE(physic_entities.size() == 1);
    REQUIRE(first_matching_entity.size() == 1);
  }

  SECTION("Fetching entity having two specific components") {
    mth::World world;

    world.spawnEntity({std::make_unique<RigidBodyComponent>(
                           rigidBodyComponentBuilder.create()),
                       std::make_unique<InventoryComponent>()});
    world.spawnEntity({std::make_unique<InventoryComponent>()});

    const auto physic_entities = world.havingComponents(
        RigidBody | Inventory);
    const auto first_matching_entity = physic_entities.at(0);

    REQUIRE(physic_entities.size() == 1);
    REQUIRE(first_matching_entity.size() == 2);
  }
}