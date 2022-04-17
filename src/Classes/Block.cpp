#include "../Headers/Block.h"

// Initializers

void Block::initShape(const float x, const float y)
{
  this->shape.setSize(sf::Vector2f(32, 32));
  this->setTexure(this->texture);
  this->shape.setPosition(sf::Vector2f(x, y));
}

// Constructor

Block::Block(const float x, const float y, sf::Texture* texture)
{
  this->texture = texture;
  this->initShape(x, y);
}

// Mutators

void Block::setTexure(sf::Texture *texture)
{
  this->shape.setTexture(texture);
}

// Functions

void Block::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
