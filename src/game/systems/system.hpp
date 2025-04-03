#ifndef SYSTEM_HPP
#define SYSTEM_HPP

namespace game {
class world;

class system {
 public:
  virtual ~system() = default;
  virtual void update(world &world, float dt) = 0;
};
}  // namespace game

#endif  // SYSTEM_HPP
