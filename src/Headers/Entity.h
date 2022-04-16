#ifndef ENTITY_H
#define ENTITY_H

#include "../Headers.h"

class Entity
{
  protected:
    sf::Texture* texture;
    sf::RectangleShape shape;

  public:
    // Constructor and Destructor
    Entity();
    virtual ~Entity();
    
    // Modifiers
    void setTexure(sf::Texture* texture);

    // Functions
    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};

#endif // ENTITY_H
