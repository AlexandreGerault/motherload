#include "input_component.hpp"

#include "component.hpp"

using namespace mth::components;

bool InputComponent::hasFlag(InputFlags flag) const {
  return (flags & static_cast<uint8_t>(flag)) != 0;
}

void InputComponent::toggleFlag(InputFlags flag) {
  flags ^= static_cast<uint8_t>(flag);
}

void InputComponent::enableFlag(InputFlags flag) {
  flags |= static_cast<uint8_t>(flag);
}

void InputComponent::disableFlag(InputFlags flag) {
  flags &= ~static_cast<uint8_t>(flag);
}

ComponentTypes InputComponent::type() { return Input; }