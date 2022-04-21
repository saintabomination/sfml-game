#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"
#include "Entity.h"

class Player : public Entity
{
  private:
    // Physics
    float speed;
    sf::Vector2f movement;

    // Initializers
    void initShape();

  public:
    // Constructor
    Player();

    // Mutators
    void setSpeed(const float speed);

    // Functions
    void update();
    void render(sf::RenderTarget& target);
    void move(sf::Vector2f movement);
};

#endif // PLAYER_H
