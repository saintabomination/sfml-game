#ifndef COLLISION_H
#define COLLISION_H

#include "../Headers.h"

class Collision
{
  public:
    // Constructor
    Collision();

    // Functions
    const bool AABB (const sf::FloatRect boxA, const sf::FloatRect boxB) const;
};

#endif // COLLISION_H
