#include "../Headers/Block.h"

// Initializers

void Block::initShape()
{
  this->shape.setSize(sf::Vector2f(32, 32));
  this->shape.setTexture(this->texture);
}

// Constructor and Destructor

Block::Block(sf::Texture* texture)
{
  this->texture = texture;
  this->initShape();
}

Block::~Block()
{

}

// Functions

void Block::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
