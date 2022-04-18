#ifndef COLLISION_H
#define COLLISION_H

#include "../Headers.h"

class Collision
{
  public:
    // Functions
    static const bool AABB (const sf::FloatRect boxA, const sf::FloatRect boxB);
};

#endif // COLLISION_H
