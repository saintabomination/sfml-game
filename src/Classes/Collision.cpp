#include "../Headers/Collision.h"

// Constructor

Collision::Collision()
{

}

// Functions

const bool Collision::AABB (const sf::FloatRect boxA, const sf::FloatRect boxB) const
{
  return (
    boxA.left + boxA.width >= boxB.left &&
    boxB.left + boxB.width >= boxA.left &&
    boxA.top + boxA.height >= boxB.top &&
    boxB.top + boxB.height >= boxA.top
  );
}
