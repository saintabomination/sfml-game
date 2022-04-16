#ifndef ENTITY_H
#define ENTITY_H

#include "../Headers.h"

class Entity
{
  private:
    sf::Texture* texture;
    sf::RectangleShape shape;
    
    // Initializers
    void initShape(const float x, const float y, const float size);

  public:
    // Constructor and Destructor
    Entity(const float x, const float y, const float size, sf::Texture* texture);
    virtual ~Entity();

    // Functions
    void update();
    void render(sf::RenderTarget& target);
};

#endif // ENTITY_H
