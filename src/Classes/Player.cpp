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

// Constructor and Destructor

Player::Player()
{

}

Player::~Player()
{

}

// Functions

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->sprite);
}

// Public Initializer

void Player::init(std::string texturePath)
{
  this->initTexture(texturePath);
  this->initSprite();
}
