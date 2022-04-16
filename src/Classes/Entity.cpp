#include "../Headers/Entity.h"

// Constructor and Destructor

Entity::Entity()
{

}

Entity::~Entity()
{

}

// Modifiers

void Entity::setTexure(sf::Texture* texture)
{
  this->shape.setTexture(texture);
}
