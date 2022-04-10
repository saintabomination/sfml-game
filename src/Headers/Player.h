#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player {
  private:
    sf::Texture texture;
    sf::Sprite sprite;

    // Initializers
    void initTexture(std::string texturePath);
    void initSprite();

  public:
    // Constructor and Destructor
    Player();
    virtual ~Player();

    // Functions
    void update();
    void render(sf::RenderTarget& target);

    // Public Initializer
    void init(std::string texturePath);
};

#endif // PLAYER_H
