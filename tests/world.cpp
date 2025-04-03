#include "../src/game/world.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("A system can require the entities having a set of components", "[world]") {

    SECTION("Fetching entity with only one component")
    {
        game::world world;

        world.spawn_entity({std::make_unique<game::physic>(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f)});
        world.spawn_entity({std::make_unique<game::inventory>()});

        const auto physic_entities = world.having_components(game::component_types::Physic);
        const auto first_matching_entity = physic_entities.at(0);

        REQUIRE(physic_entities.size() == 1);
        REQUIRE(first_matching_entity.size() == 1);
    }

    SECTION("Fetching entity having two specific components")
    {
        game::world world;

        world.spawn_entity({
            std::make_unique<game::physic>(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f),
            std::make_unique<game::inventory>()
        });
        world.spawn_entity({std::make_unique<game::inventory>()});

        const auto physic_entities = world.having_components(game::component_types::Physic | game::component_types::Inventory);
        const auto first_matching_entity = physic_entities.at(0);

        REQUIRE(physic_entities.size() == 1);
        REQUIRE(first_matching_entity.size() == 2);
    }
}