#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player {
  private:
    sf::Texture texture;
    sf::Sprite sprite;

    // Physics
    float speed;

    // Initializers
    void initTexture(std::string texturePath);
    void initSprite();

  public:
    // Constructor and Destructor
    Player();
    virtual ~Player();

    // Setters
    void setTexture(std::string texturePath);
    void setSpeed(const float speed);

    // Functions
    void update();
    void render(sf::RenderTarget& target);
    void move(const int x, const int y);
};

#endif // PLAYER_H
