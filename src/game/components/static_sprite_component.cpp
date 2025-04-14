#include "static_sprite_component.hpp"

using namespace mth::components;

StaticSpriteComponent::StaticSpriteComponent(const TextureId textureId,
                                             const Rectangle clip)
    : m_textureId{textureId}, m_clip{clip} {}

ComponentTypes StaticSpriteComponent::type() { return StaticSprite; }