#include "../Headers/Bullet.h"

// Initializers

void Bullet::initShape(const float x, const float y)
{
  this->shape.setSize(sf::Vector2f(8.f, 8.f));
  this->shape.setTexture(this->texture);
  this->shape.setPosition(sf::Vector2f(x, y));
}

// Constructor and Destructor

Bullet::Bullet(const float x, const float y, sf::Texture* texture)
{
  this->texture = texture;
  this->initShape(x, y);
}

Bullet::~Bullet()
{

}

// Functions

void Bullet::update()
{

}

void Bullet::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
