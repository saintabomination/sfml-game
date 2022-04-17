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
  else
  {
    configFile >> windowTitle >> windowWidth >> windowHeight >> windowFPS;
  }

  this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);
  this->window->setFramerateLimit(windowFPS);
}

void Game::initPlayer()
{
  this->player.setTexture(&this->textures[0]);
  this->player.setSpeed(80.f);
}

// Non-member function to simplify loading textures
sf::Texture loadTexture(std::string path)
{
  sf::Texture loadedTexture;
  if (!loadedTexture.loadFromFile(path))
  {
    std::cout << "ERROR::GAME::CANT_LOAD_TEXTURE" << std::endl;
  }

  return loadedTexture;
}

void Game::initTextures()
{
  this->textures.push_back(loadTexture("src/Assets/Textures/player.png"));
  this->textures.push_back(loadTexture("src/Assets/Textures/block.png"));
  this->textures.push_back(loadTexture("src/Assets/Textures/bullet.png"));
}

void Game::initSettings()
{
  this->bulletInterval = 0.2f;
  this->bulletDespawnTime = 1.f;
}

void Game::initBlocks()
{
  sf::Image mapImage;
  if (!mapImage.loadFromFile("src/Assets/Maps/testing.png"))
  {
    std::cout << "ERROR::GAME::CANT_LOAD_MAP" << std::endl;
  }

  // Convert all the black pixels into blocks
  for (int y = 0; y < mapImage.getSize().y; y++)
  {
    for (int x = 0; x < mapImage.getSize().x; x++)
    {
      if (mapImage.getPixel(x, y) == sf::Color::Black)
      {
        this->blocks.push_back(Block(x * 32.f, y * 32.f, &this->textures[1]));
      }
    }
  }
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
  this->initTextures();
  this->initSettings();
  this->initPlayer();
  this->initBlocks();
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

void Game::updateClocks()
{
  // Delta Time
  this->dt = this->dtClock.restart().asSeconds();

  // Bullet Spawn Clock
  this->bulletSpawnTimer = this->bulletSpawnClock.getElapsedTime().asSeconds();
}

void Game::updateKeys()
{
  // WASD Movement
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

  // Debug: Spawning bullets
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) && this->bulletSpawnTimer > this->bulletInterval)
  {
    this->bullets.push_back(
      Bullet(
        this->player.getBounds().left + 12.f,
        this->player.getBounds().top + 12.f,
        // Getting the bullet angle by calculating sine
        (
          (MAX_VALUE(0, this->player.getBounds().top) - MIN_VALUE(0, this->player.getBounds().top)) /
          (sqrt(pow(fabs(0 - this->player.getBounds().left), 2) + pow(fabs(0 - this->player.getBounds().top), 2)))
        ),
        &this->textures[2]
      )
    );
    this->bulletSpawnClock.restart();
  }
}

void Game::updatePlayer()
{
  this->player.update();
}

void Game::updateView()
{
  // Centering the camera
  this->window->setView(sf::View(
    sf::FloatRect(
      this->player.getBounds().left - this->window->getSize().x / 2 + 16,
      this->player.getBounds().top - this->window->getSize().y / 2 + 16,
      this->window->getSize().x,
      this->window->getSize().y
    )
  ));
}

void Game::updateBullets()
{
  for (Bullet bullet : this->bullets) bullet.update();
}

void Game::updateBulletDespawns()
{
  for (int i = 0; i < this->bullets.size(); i++)
  {
    this->bullets[i].getDespawnTimer();
    if (this->bullets[i].getDespawnTimer() > 2)
    {
      this->bullets.erase(this->bullets.begin() + i);
    }
  }
}

void Game::update()
{
  this->updateSFMLEvents();
  this->updateClocks();
  this->updateKeys();
  this->updatePlayer();
  this->updateView();
  this->updateBullets();
  this->updateBulletDespawns();
}

// Render Functions

void Game::renderPlayer()
{
  this->player.render(*this->window);
}

void Game::renderBlocks()
{
  for (Block block : this->blocks) block.render(*this->window);
}

void Game::renderBullets()
{
  for (Bullet bullet : this->bullets) bullet.render(*this->window);
}

void Game::render()
{
  this->window->clear();
  this->renderPlayer();
  this->renderBlocks();
  this->renderBullets();
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
