#include "../Headers/Entity.h"

// Mutators

void Entity::setTexture(sf::Texture *texture)
{
  this->shape.setTexture(texture);
}

void Entity::setPosition(sf::Vector2f position)
{
  this->shape.setPosition(position);
}

// Accessors

const sf::FloatRect Entity::getBounds() const
{
  return this->shape.getGlobalBounds();
}
