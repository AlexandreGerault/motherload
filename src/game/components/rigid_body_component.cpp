#include "rigid_body_component.hpp"

using namespace mth;

RigidBodyComponent::RigidBodyComponent(float mass, float drag, bool useGravity,
                                       bool collisionDetection)
    : mass{mass},
      drag{drag},
      useGravity{useGravity},
      collisionDetection{collisionDetection} {}

ComponentTypes RigidBodyComponent::type() { return RigidBody; }

RigidBodyComponentBuilder RigidBodyComponentBuilder::withMass(float mass) {
  this->mass = mass;

  return *this;
}

RigidBodyComponentBuilder RigidBodyComponentBuilder::withDrag(float drag) {
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

RigidBodyComponent RigidBodyComponentBuilder::create() {
  return RigidBodyComponent(mass, drag, useGravity, collisionDetection);
}
