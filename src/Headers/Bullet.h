#ifndef BULLET_H
#define BULLET_H

#include "../Headers.h"
#include "Entity.h"

class Bullet : public Entity
{
  private:
    float angle;

    // Initializers
    void initShape(const float x, const float y);

    // Despawn Clock
    sf::Clock despawnClock;

  public:
    // Constructor and Destructor
    Bullet(const float x, const float y, const float angle, sf::Texture* texture);

    // Accessors
    const float getAngle();
    const float getDespawnTimer();

    // Functions
    void update();
    void render(sf::RenderTarget& target);
};

#endif // BULLET_H
