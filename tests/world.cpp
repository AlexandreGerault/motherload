#include "../src/game/world.hpp"

#include <catch2/catch_test_macros.hpp>

#include "../src/game/components/rigid_body_component.hpp"


TEST_CASE("A system can require the entities having a set of components",
          "[world]") {
  SECTION("Fetching entity with only one component") {
    mth::World world;

    world.spawnEntity({std::make_unique<mth::RigidBodyComponent>(
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)});
    world.spawnEntity({std::make_unique<mth::InventoryComponent>()});

    const auto physic_entities =
        world.havingComponents(mth::ComponentTypes::RigidBody);
    const auto first_matching_entity = physic_entities.at(0);

    REQUIRE(physic_entities.size() == 1);
    REQUIRE(first_matching_entity.size() == 1);
  }

  SECTION("Fetching entity having two specific components") {
    mth::World world;

    world.spawnEntity({std::make_unique<mth::RigidBodyComponent>(
                           0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f),
                       std::make_unique<mth::InventoryComponent>()});
    world.spawnEntity({std::make_unique<mth::InventoryComponent>()});

    const auto physic_entities = world.havingComponents(
        mth::ComponentTypes::RigidBody | mth::ComponentTypes::Inventory);
    const auto first_matching_entity = physic_entities.at(0);

    REQUIRE(physic_entities.size() == 1);
    REQUIRE(first_matching_entity.size() == 2);
  }
}