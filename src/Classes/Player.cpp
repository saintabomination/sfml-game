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

void Player::initPhysics()
{
    this->movementSpeed = 20.f;
}

// Constructor and Destructor

Player::Player()
{
  this->initPhysics();
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

void Player::move(const int x, const int y)
{
  this->sprite.move(sf::Vector2f(x * this->movementSpeed, y * this->movementSpeed));
  std::cout << "Player Position: " << this->sprite.getGlobalBounds().left << "; " << this->sprite.getGlobalBounds().top << std::endl;
}
