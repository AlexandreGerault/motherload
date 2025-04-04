#include "vec_2.hpp"

namespace mth::math {
Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
  return Vec2{lhs.x + rhs.x, lhs.y + rhs.y};
}

Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
  return Vec2{lhs.x - rhs.x, lhs.y - rhs.y};
}

Vec2 operator*(const Vec2& lhs, const float rhs) {
  return Vec2{lhs.x * rhs, lhs.y * rhs};
}
}  // namespace mth::math
