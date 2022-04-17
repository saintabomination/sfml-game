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

// Constructor and Destructor

Bullet::Bullet(const float x, const float y, const float angle, sf::Texture* texture)
{
  this->texture = texture;
  this->angle = angle;
  this->initShape(x, y);
}

Bullet::~Bullet()
{

}

// Accessors

const float Bullet::getDespawnTimer()
{
  return this->despawnClock.getElapsedTime().asSeconds();
}

// Functions

void Bullet::update()
{
  this->shape.move(sf::Vector2f(cos(this->angle), sin(this->angle)) * 96.f * game.getDt());
}

void Bullet::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
