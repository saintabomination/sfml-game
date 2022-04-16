#include "../Headers/Player.h"
#include "../Headers/Game.h"

extern Game game;

// Initializers

void Player::initShape()
{
  this->shape.setSize(sf::Vector2f(32.f, 32.f));
}

// Constructor and Destructor

Player::Player()
{
  this->initShape();
}

Player::~Player()
{

}

// Modifiers

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
  
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}

void Player::move(const int x, const int y)
{
  this->shape.move(
    sf::Vector2f(
      x * this->speed * game.getDt(),
      y * this->speed * game.getDt()
    )
  );
}
