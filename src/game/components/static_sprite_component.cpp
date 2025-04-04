#include "static_sprite_component.hpp"

using namespace mth;

StaticSpriteComponent::StaticSpriteComponent(const TextureId textureId,
                                             const Rectangle rectangle)
    : m_textureId{textureId}, m_clip{rectangle} {}