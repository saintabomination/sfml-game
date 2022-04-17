#include "../Headers/Bullet.h"
#include "../Headers/Game.h"

extern Game game;

// Initializers

void Bullet::initShape(const float x, const float y)
{
  this->shape.setSize(sf::Vector2f(8.f, 8.f));
  this->shape.setTexture(this->texture);
  this->shape.setPosition(sf::Vector2f(x, y));
}

// Constructor

Bullet::Bullet(const float x, const float y, const sf::Vector2f bulletMovement, sf::Texture* texture)
{
  this->texture = texture;
  this->movement = bulletMovement;
  this->initShape(x, y);
}

// Accessors

const float Bullet::getDespawnTimer()
{
  return this->despawnClock.getElapsedTime().asSeconds();
}

// Functions

void Bullet::update()
{
  this->shape.move(this->movement * game.getDt() * 96.f);
}

void Bullet::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
