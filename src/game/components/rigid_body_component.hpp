#ifndef RIGID_BODY_COMPONENT_H
#define RIGID_BODY_COMPONENT_H
#include "component.hpp"

namespace mth {
struct RigidBodyComponent final : Component {
  bool useGravity{false};

  float mass{1};

  float drag{1};

  bool collisionDetection{false};

  RigidBodyComponent() = delete;

  RigidBodyComponent(float mass, float drag, bool useGravity,
                     bool collisionDetection);

  ComponentTypes type() override;
};

struct RigidBodyComponentBuilder {
  bool useGravity{false};

  float mass{1};

  float drag{1};

  bool collisionDetection{false};

  RigidBodyComponentBuilder() = default;

  RigidBodyComponentBuilder withMass(float mass);

  RigidBodyComponentBuilder withDrag(float drag);

  RigidBodyComponentBuilder withGravity();

  RigidBodyComponentBuilder withoutGravity();

  RigidBodyComponentBuilder withCollision();

  RigidBodyComponentBuilder withoutCollision();

  RigidBodyComponent create();
};
}  // namespace mth

#endif  // RIGID_BODY_COMPONENT_H
