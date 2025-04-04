#ifndef SYSTEM_HPP
#define SYSTEM_HPP

namespace mth {
class World;

class System {
 public:
  virtual ~System() = default;
  virtual void update(World &world, float dt) = 0;
};
}  // namespace mth

#endif  // SYSTEM_HPP
