#include "rectangle.hpp"

mth::math::Rectangle::Rectangle(const Vec2& position, const Vec2& size)
    : x(position.x), y(position.y), width(size.x), height(size.y) {}

mth::math::Rectangle::Rectangle(const float x, const float y, const float width,
                                const float height)
    : x(x), y(y), width(width), height(height) {}