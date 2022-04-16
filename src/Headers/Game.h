#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "Player.h"
#include "Block.h"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;
    Player player;
    std::vector<sf::Texture> textures;
    std::vector<Block> blocks;

    // Delta Time
    sf::Clock dtClock;
    float dt;

    // Initializers
    void initWindow();
    void initPlayer();
    void initTextures();
    void initBlocks();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Accessors
    const float getDt() const;

    // Update Functions
    void updateSFMLEvents();
    void updateDt();
    void updateKeys();
    void updatePlayer();
    void updateView();
    void update();

    // Render Functions
    void renderPlayer();
    void renderBlocks();
    void render();

    // Functions
    void run();
};

#endif // GAME_H
