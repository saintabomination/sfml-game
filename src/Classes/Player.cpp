#include "../Headers/Player.h"
#include "../Headers/Game.h"

extern Game game;

// Initializers

void Player::initShape()
{
  this->shape.setSize(sf::Vector2f(32.f, 32.f));
  this->shape.setPosition(sf::Vector2f(64.f, 64.f));
}

// Constructor

Player::Player()
{
  this->initShape();
}

// Mutators

void Player::setTexture(sf::Texture* texture)
{
  this->shape.setTexture(texture);
}

void Player::setSpeed(const float speed)
{
  this->speed = speed;
}

// Accessors

const sf::FloatRect Player::getBounds() const
{
  return this->shape.getGlobalBounds();
}

// Functions

void Player::update()
{
  sf::Vector2f normalisedVector = this->movement;

  // Normalising vector to prevent moving faster than the maximum speed
  if (std::abs(this->movement.x) == 1 && std::abs(this->movement.y))
  {
    normalisedVector /= sqrtf(pow(this->movement.x, 2) + pow(this->movement.y, 2));
  }

  this->shape.move(normalisedVector * this->speed * game.getDt());
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}

void Player::move(sf::Vector2f movement)
{
  this->movement = movement;
}
