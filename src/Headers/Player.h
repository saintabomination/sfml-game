#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player {
  private:
    sf::Texture texture;
    sf::Sprite sprite;

    // Physics
    float movementSpeed = 20.f;

    // Initializers
    void initTexture(std::string texturePath);
    void initSprite();
    void initPhysics();

  public:
    // Constructor and Destructor
    Player();
    virtual ~Player();

    // Public Initializer
    void init(std::string texturePath);

    // Functions
    void update();
    void render(sf::RenderTarget& target);
    void move(const int x, const int y);
};

#endif // PLAYER_H
