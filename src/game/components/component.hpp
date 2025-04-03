#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <memory>
#include <vector>

namespace game
{
    enum component_types
    {
        Physic = 1 << 0,
        Inventory = 1 << 1,
        Texture = 1 << 2,
    };

    struct component
    {
        virtual ~component() = default;
        virtual component_types get_component_type() = 0;
    };

    struct physic final : component
    {
        float x;
        float y;

        float sx;
        float sy;

        float ax;
        float ay;

        physic() = delete;

        physic(const float _x, const float _y, const float _sx, const float _sy, const float _ax,
               const float _ay): x{_x}, y{_y}, sx{_sx}, sy{_sy}, ax{_ax}, ay{_ay} {};

        component_types get_component_type() override
        {
            return Physic;
        }
    };

    struct inventory final : component
    {
        component_types get_component_type() override
        {
            return Inventory;
        }
    };

    typedef std::vector<std::shared_ptr<component>> component_list;
}


#endif //COMPONENT_HPP
