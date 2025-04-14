#include "vec_2.hpp"

namespace mth::math {
Vec2& Vec2::operator+=(const Vec2& rhs) {
  x += rhs.x;
  y += rhs.y;

  return *this;
}

Vec2& Vec2::operator*=(const float lhs) {
  x *= lhs;
  y *= lhs;

  return *this;
}

Vec2& Vec2::operator-=(const Vec2& rhs) {
  x -= rhs.x;
  y -= rhs.y;

  return *this;
}

// Implementation of non-member operator* functions
Vec2 operator*(const Vec2& lhs, float rhs) {
  return Vec2{lhs.x * rhs, lhs.y * rhs};
}

Vec2 operator*(float lhs, const Vec2& rhs) {
  return Vec2{lhs * rhs.x, lhs * rhs.y};
}

Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
  return Vec2{lhs.x + rhs.x, lhs.y + rhs.y};
}

Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
  return Vec2{lhs.x - rhs.x, lhs.y - rhs.y};
}
}  // namespace mth::math