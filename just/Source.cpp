#include <SFML/Graphics.hpp>
#include <vector>
#include "snake.h"
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 640), "SFML works!");

    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    int windowX = window.getSize().x;
    int windowY = window.getSize().y;
    std::vector<CircleShape> apples(4);
    bool is_drawed = false;
    Vector2f size = Vector2f(20, 20);
    RectangleShape apple = RectangleShape(size);
    RectangleShape line;
    Snake snake;
    snake.initSnake();
    snake.setWindow(window);
    while (window.isOpen())
    {
        Event event;
        apple.setFillColor(Color::Blue);
        window.setFramerateLimit(60);
        window.clear(Color::White);
        line.setSize(Vector2f(windowY, 1));
        line.setFillColor(Color::Black);
        line.rotate(90);
        for (int i = 0; i <= windowX; i += 20) {
            line.setPosition(Vector2f(i, 0));
            window.draw(line);
        }
        line.setSize(Vector2f(windowX, 1));
        line.rotate(-90);
        for (int i = 0; i <= windowY; i += 20) {
            line.setPosition(Vector2f(0, i));
            window.draw(line);
        }
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.draw(apple);
        snake.setDirection(event);
        snake.update();
        for (int i = 0; i < snake.getTails(); i++) {
            window.draw(snake.getSnake(i));
        }
        window.display();
    }
    return 0;
}
