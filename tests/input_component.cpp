#include "../src/game/components/input_component.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace mth::components;
TEST_CASE("An input component can be created and flags can be set",
          "[components::input]") {
  SECTION("Toggle a flag") {
    InputComponent inputComponent{};

    inputComponent.toggleFlag(InputFlags::Up);

    REQUIRE(inputComponent.hasFlag(InputFlags::Up) == true);
  }

  SECTION("Enable a flag") {
    InputComponent inputComponent{};

    inputComponent.enableFlag(InputFlags::Up);

    REQUIRE(inputComponent.hasFlag(InputFlags::Up) == true);
  }

  SECTION("Disable a flag") {
    InputComponent inputComponent{};

    inputComponent.enableFlag(InputFlags::Up);
    inputComponent.disableFlag(InputFlags::Up);

    REQUIRE(inputComponent.hasFlag(InputFlags::Up) == false);
  }
}