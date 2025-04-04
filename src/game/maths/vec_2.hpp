#ifndef VEC_2_HPP
#define VEC_2_HPP

namespace mth::math {
struct Vec2 {
  float x{0.0f};
  float y{0.0f};

  Vec2 operator+(const Vec2& rhs) const;
  Vec2 operator-(const Vec2& rhs) const;
  Vec2 operator*(float rhs) const;
};

}  // namespace mth::math

#endif  // VEC_2_HPP
