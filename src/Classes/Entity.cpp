#include "../Headers/Entity.h"

// Initializers

void Entity::initShape(const float x, const float y, const float size)
{
  this->shape.setSize(sf::Vector2f(size, size));
  this->shape.setTexture(this->texture);
  this->shape.setPosition(x, y);
}

// Constructor and Destructor

Entity::Entity(const float x, const float y, const float size, sf::Texture* texture)
{
  this->texture = texture;
  this->initShape(x, y, size);
}

Entity::~Entity()
{

}

// Functions

void Entity::update()
{

}

void Entity::render(sf::RenderTarget &target)
{
  target.draw(this->shape);
}
