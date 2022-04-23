#ifndef GAME_H
#define GAME_H

#define PI 3.14159265

#include "../Headers.h"
#include "Player.h"
#include "Block.h"
#include "Bullet.h"
#include "BackgroundRect.h"
#include "Collision.h"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::View view;
    sf::Event sfEvent;
    Player player;
    sf::FloatRect oldPlayerPosition;
    std::vector<sf::Texture> textures;
    std::vector<sf::SoundBuffer> sounds;
    std::vector<Block> blocks;
    std::vector<Bullet> bullets;
    std::vector<BackgroundRect> backgroundRects;

    // Settings
    float bulletInterval;
    float bulletDespawnTime;

    // Clocks
    sf::Clock dtClock;
    sf::Clock bulletSpawnClock;
    float dt;
    float bulletSpawnTimer;

    // Initializers
    void initWindow();
    void initTextures();
    void initSounds();
    void initSettings();
    void initPlayer();
    void initBlocks();
    void initBackgroundRects();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Accessors
    const float getDt() const;

    // Update Functions
    void updateSFMLEvents();
    void updateClocks();
    void updateKeys();
    void updateMouse();
    void updatePlayer();
    void updateView();
    void updateBullets();
    void updateBulletDespawns();
    void updateCollisions();
    void update();

    // Render Functions
    void renderBackgroundRects();
    void renderPlayer();
    void renderBlocks();
    void renderBullets();
    void render();

    // Functions
    void run();
};

#endif // GAME_H
