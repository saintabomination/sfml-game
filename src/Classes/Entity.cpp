#include "../Headers/Entity.h"

// Accessors

const sf::FloatRect Entity::getBounds() const
{
  return this->shape.getGlobalBounds();
}
