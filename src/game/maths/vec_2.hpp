#ifndef VEC_2_HPP
#define VEC_2_HPP

namespace mth::math {
struct Vec2 {
  float x{0.0f};
  float y{0.0f};

  Vec2& operator+=(const Vec2& rhs);

  Vec2& operator*=(const float rhs);

  Vec2& operator-=(const Vec2& rhs);
};

// Non-member operator* functions
Vec2 operator*(const Vec2& lhs, float rhs);
Vec2 operator*(float lhs, const Vec2& rhs);

// Non-member operator+ functions
Vec2 operator+(const Vec2& lhs, const Vec2& rhs);
Vec2 operator-(const Vec2& lhs, const Vec2& rhs);
}  // namespace mth::math
#endif  // VEC_2_HPP
