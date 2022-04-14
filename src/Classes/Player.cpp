#include "../Headers/Player.h"

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

void Player::initValues()
{
  this->x = 0.f;
  this->y = 0.f;
}

// Constructor and Destructor

Player::Player()
{
  this->initValues();
}

Player::~Player()
{

}

// Public Initializer

void Player::init(std::string texturePath)
{
  this->initTexture(texturePath);
  this->initSprite();
}

// Functions

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->sprite);
}

void Player::move(const float x, const float y)
{
  this->x += x;
  this->y += y;

  std::cout << "Player Position: " << this->x << "; " << this->y << std::endl;
}
