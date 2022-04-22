#ifndef BLOCK_H
#define BLOCK_H

#include "../Headers.h"

class Block
{
  private:
    sf::Texture* texture;
    sf::RectangleShape shape;

    // Initializers
    void initShape(const float x, const float y);

  public:
    // Constructor
    Block(const float x, const float y, sf::Texture* texture);

    // Mutators
    void setTexure(sf::Texture* texture);

    // Accessors
    const sf::FloatRect getBounds() const;

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BLOCK_H
