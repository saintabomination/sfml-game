#include "Headers.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main()
{
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML");
  sf::CircleShape shape(20.f);
  shape.setFillColor(sf::Color::Red);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;

        default:
          break;
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
