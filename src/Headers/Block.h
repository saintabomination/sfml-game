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
    // Constructor and Destructor
    Block(const float x, const float y, sf::Texture* texture);
    virtual ~Block();

    // Mutators
    void setTexure(sf::Texture* texture);

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BLOCK_H
