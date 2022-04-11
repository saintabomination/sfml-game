#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "Player.h"

class Game {
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;
    Player player;

    // Delta Time
    sf::Clock dtClock;
    float dt;

    // Initializers
    void initWindow();
    void initPlayer();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Accessors
    const float getDt() const;

    // Update Functions
    void updateSFMLEvents();
    void updateDt();
    void updatePlayer();
    void update();

    // Render Functions
    void renderPlayer();
    void render();

    // Functions
    void run();
};

#endif // GAME_H
