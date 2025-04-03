#include "render_system.hpp"

#include "../world.hpp"

void game::render_system::update(world& world, float dt)
{
    const auto entities = world.having_components(Physic | Texture);
}
