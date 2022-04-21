#include "../Headers/BackgroundRect.h"

// Initializers
void BackgroundRect::initShape(sf::Vector2f position, sf::Vector2f size)
{
  this->shape.setPosition(position);
  this->shape.setSize(size);
  this->shape.setTexture(this->texture);
}

// Constructor

BackgroundRect::BackgroundRect(sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
{
  this->texture = texture;
  this->initShape(position, size);
}

// Functions

void BackgroundRect::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
