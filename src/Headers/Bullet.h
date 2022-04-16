#ifndef BULLET_H
#define BULLET_H

#include "../Headers.h"
#include "Entity.h"

class Bullet : public Entity
{
  private:
    // Initializers
    void initShape(const float x, const float y);

  public:
    // Constructor and Destructor
    Bullet(const float x, const float y, sf::Texture* texture);
    virtual ~Bullet();

    // Functions
    void update();
    void render(sf::RenderTarget& target);
};

#endif // BULLET_H
