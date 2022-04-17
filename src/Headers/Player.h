#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"
#include "Entity.h"

class Player : public Entity
{
  private:
    // Physics
    float speed;

    // Initializers
    void initShape();

  public:
    // Constructor and Destructor
    Player();
    virtual ~Player();

    // Mutators
    void setTexture(sf::Texture* texture);
    void setSpeed(const float speed);

    // Accessors
    const sf::FloatRect getBounds() const;

    // Functions
    void update();
    void render(sf::RenderTarget& target);
    void move(const int x, const int y);
};

#endif // PLAYER_H
