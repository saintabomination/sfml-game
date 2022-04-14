#include "../Headers/Game.h"

// Initializers

void Game::initWindow()
{
  this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML");
  this->window->setFramerateLimit(60);
}

void Game::initPlayer()
{
  this->player.init("src/Assets/Textures/player.png");
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
  this->initPlayer();
}

Game::~Game()
{
  delete this->window; 
}

// Accessors

const float Game::getDt() const
{
  return this->dt;
}

// Update Functions

void Game::updateSFMLEvents()
{
  while (this->window->pollEvent(this->sfEvent))
  {
    switch (this->sfEvent.type)
    {
      case sf::Event::Closed:
        this->window->close();
        break;

      default:
        break;
    }
  }
}

void Game::updateDt()
{
  this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateMovement()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
  {
    player.move(0, -1);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
  {
    player.move(0, 1);
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    player.move(-1, 0);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    player.move(1, 0);
  }
}

void Game::updatePlayer()
{
  this->player.update();
}

void Game::update()
{
  this->updateSFMLEvents();
  this->updateDt();
  this->updateMovement();
  this->updatePlayer();
}

// Render Functions

void Game::renderPlayer()
{
  this->player.render(*this->window);
}

void Game::render()
{
  this->window->clear();
  this->renderPlayer();
  this->window->display();
}

// Functions

void Game::run()
{
  while (this->window->isOpen())
  {
    this->update();
    this->render();
  }
}
