#ifndef MOVEMENT_SYSTEM_HPP
#define MOVEMENT_SYSTEM_HPP
#include "system.hpp"

namespace game
{
    class movement_system final : public system
    {
    public:
        movement_system() = default;
        ~movement_system() override = default;

        void update(world& world, float dt) override;
    };
}

#endif //MOVEMENT_SYSTEM_HPP
