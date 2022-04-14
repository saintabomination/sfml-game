#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player {
  private:
    sf::Texture texture;
    sf::Sprite sprite;

    // Position
    float x;
    float y;

    // Initializers
    void initTexture(std::string texturePath);
    void initSprite();
    void initValues();

  public:
    // Constructor and Destructor
    Player();
    virtual ~Player();

    // Public Initializer
    void init(std::string texturePath);

    // Functions
    void update();
    void render(sf::RenderTarget& target);
    void move(const float x, const float y);
};

#endif // PLAYER_H
