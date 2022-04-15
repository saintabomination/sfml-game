#include "../Headers/Game.h"

// Initializers

void Game::initWindow()
{
  std::string windowTitle = "SFML";
  unsigned int windowWidth = 400;
  unsigned int windowHeight = 300;
  unsigned int windowFPS = 60;

  std::ifstream configFile("src/Config/Window.ini");
  if (!configFile.is_open())
  {
    std::cout << "ERROR::GAME::CANT_LOAD_WINDOW_CONFIG" << std::endl;
  }

  std::string line;
  while (getline(configFile, line))
  {
    std::cout << line << std::endl;
  }

  this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowWidth), windowTitle);
  this->window->setFramerateLimit(windowFPS);
}

void Game::initPlayer()
{
  this->player.setTexture("src/Assets/Textures/player.png");
  this->player.setSpeed(80.f);
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
