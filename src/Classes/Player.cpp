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

void Player::initPhysics()
{
    this->movementSpeed = 80.f;
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
  this->sprite.move(
    sf::Vector2f(
      x * this->movementSpeed * game.getDt(),
      y * this->movementSpeed * game.getDt()
    )
  );

  std::cout << "Player Position: " << this->sprite.getGlobalBounds().left << "; " << this->sprite.getGlobalBounds().top << std::endl;
}
