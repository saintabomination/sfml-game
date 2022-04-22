#include "../Headers/Block.h"

// Initialisers

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

// Accessors

const sf::FloatRect Block::getBounds() const
{
  return this->shape.getGlobalBounds();
}

// Functions

void Block::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
