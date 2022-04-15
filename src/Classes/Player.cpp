#include "../Headers/Player.h"
#include "../Headers/Game.h"

extern Game game;

// Initializers

void Player::initTexture(std::string texturePath)
{
  if (!this->texture.loadFromFile(texturePath))
  {
    std::cout << "ERROR::PLAYER::CANT_LOAD_TEXTURE" << std::endl;
  }
}

void Player::initSprite()
{
  this->sprite.setTexture(this->texture);
}

// Constructor and Destructor

Player::Player()
{

}

Player::~Player()
{

}

// Setters

void Player::setTexture(std::string texturePath)
{
  this->initTexture(texturePath);
  this->initSprite();
}

void Player::setSpeed(const float speed)
{
  this->speed = speed;
}

// Accessors

const sf::FloatRect Player::getBounds() const
{
  return this->sprite.getGlobalBounds();
}

// Functions

void Player::update()
{
  
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->sprite);
}

void Player::move(const int x, const int y)
{
  this->sprite.move(
    sf::Vector2f(
      x * this->speed * game.getDt(),
      y * this->speed * game.getDt()
    )
  );
}
