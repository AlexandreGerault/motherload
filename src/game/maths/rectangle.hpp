#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec_2.hpp"

namespace mth::math {
struct Rectangle {
  float x{};
  float y{};

  float width{};
  float height{};

  Rectangle() = delete;
  explicit Rectangle(const Vec2& position, const Vec2& size);
  explicit Rectangle(float x, float y, float width, float height);
};
}  // namespace mth::math

#endif  // RECTANGLE_HPP
