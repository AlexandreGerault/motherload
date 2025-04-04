#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include <memory>

#include "../renderer.hpp"
#include "system.hpp"

namespace mth {
class RenderSystem final : public System {
 public:
  RenderSystem() = delete;
  explicit RenderSystem(std::unique_ptr<Renderer> renderer);

  void update(World &world, float dt) override;

 private:
  std::unique_ptr<Renderer> m_renderer;
};
}  // namespace mth

#endif  // RENDER_SYSTEM_HPP
