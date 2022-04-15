#ifndef BLOCK_H
#define BLOCK_H

#include "../Headers.h"

class Block
{
  private:
    sf::Texture* texture;
    sf::RectangleShape shape;

    // Initializers
    void initShape();

  public:
    // Constructor and Destructor
    Block(sf::Texture* texture);
    virtual ~Block();

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BLOCK_H
