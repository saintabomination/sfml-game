#ifndef BULLET_H
#define BULLET_H

#include "../Headers.h"

class Bullet
{
  private:
    sf::Texture* texture;
    sf::RectangleShape shape;

    // Initializers
    void initShape(const float x, const float y);

  public:
    // Constructor and Destructor
    Bullet(const float x, const float y, sf::Texture* texture);
    virtual ~Bullet();

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BULLET_H
