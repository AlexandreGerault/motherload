#include "rigid_body_component.hpp"

using namespace mth::components;

RigidBodyComponent::RigidBodyComponent(const float mass, const float drag,
                                       const bool useGravity,
                                       const bool collisionDetection)
    : useGravity{useGravity},
      mass{mass},
      drag{drag},
      collisionDetection{collisionDetection} {}

ComponentTypes RigidBodyComponent::type() { return RigidBody; }

RigidBodyComponentBuilder RigidBodyComponentBuilder::withMass(
    const float mass) {
  this->mass = mass;

  return *this;
}

RigidBodyComponentBuilder RigidBodyComponentBuilder::withDrag(
    const float drag) {
  this->drag = drag;

  return *this;
}

RigidBodyComponentBuilder RigidBodyComponentBuilder::withGravity() {
  this->useGravity = true;

  return *this;
}

RigidBodyComponentBuilder RigidBodyComponentBuilder::withoutGravity() {
  this->useGravity = false;

  return *this;
}

RigidBodyComponentBuilder RigidBodyComponentBuilder::withCollision() {
  this->collisionDetection = true;

  return *this;
}

RigidBodyComponentBuilder RigidBodyComponentBuilder::withoutCollision() {
  this->collisionDetection = false;

  return *this;
}

RigidBodyComponent RigidBodyComponentBuilder::create() const {
  return RigidBodyComponent{mass, drag, useGravity, collisionDetection};
}
