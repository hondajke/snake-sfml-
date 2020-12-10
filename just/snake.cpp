#include "snake.h"

void Snake::initSnake() {
    sf::RectangleShape snakeBlock = sf::RectangleShape(sf::Vector2f(x, y));
    snakeBlock.setFillColor(sf::Color::Black);
    for (int i = 0; i < tails; i++) {
        snake.push_back(snakeBlock);
    }
}

void Snake::setDirection(sf::Event events) {
    if (events.type == sf::Event::EventType::KeyPressed) {
        switch (events.key.code)
        {
        case sf::Keyboard::Left:
            if (direction != 1)
                direction = 3;
            break;
        case sf::Keyboard::Right:
            if (direction != 3)
                direction = 1;
            break;
        case sf::Keyboard::Up:
            if (direction != 2)
                direction = 4;
            break;
        case sf::Keyboard::Down:
            if (direction != 4)
                direction = 2;
            break;
        default:
            break;
        }
    }
}

void Snake::update() {
    float time = clock.getElapsedTime().asSeconds();
    if (time > speed) {
        switch (direction) {
        case 1:
            /*if (snake[0].getPosition() == apple.getPosition()) {
                tails++;
            }*/
            if (snake[0].getPosition().x >= windowX - x) {
                for (int i = tails - 1; i > 0; i--) {
                    snake[i].setPosition(snake[i - 1].getPosition());
                }
                snake[0].setPosition(sf::Vector2f(0, snake[0].getPosition().y));
            }
            else {
                for (int i = tails - 1; i > 0; i--) {
                    snake[i].setPosition(snake[i - 1].getPosition());
                }
                snake[0].setPosition(sf::Vector2f(snake[0].getPosition().x + x, snake[0].getPosition().y));
            }
            break;
        case 2:
            /*if (snake[0].getPosition() == apple.getPosition()) {
                tails++;
            }*/
            if (snake[0].getPosition().y >= windowY - y) {
                for (int i = tails - 1; i > 0; i--) {
                    snake[i].setPosition(snake[i - 1].getPosition());
                }
                snake[0].setPosition(sf::Vector2f(snake[0].getPosition().x, 0));
            }
            else {
                for (int i = tails - 1; i > 0; i--) {
                    snake[i].setPosition(snake[i - 1].getPosition());
                }
                snake[0].setPosition(sf::Vector2f(snake[0].getPosition().x, snake[0].getPosition().y + y));
            }
            break;
        case 3:
            /*if (snake[0].getPosition() == apple.getPosition()) {
                tails++;
            }*/
            if (snake[0].getPosition().x <= 0) {
                for (int i = tails - 1; i > 0; i--) {
                    snake[i].setPosition(snake[i - 1].getPosition());
                }
                snake[0].setPosition(sf::Vector2f(windowX - x, snake[0].getPosition().y));
            }
            else {
                for (int i = tails - 1; i > 0; i--) {
                    snake[i].setPosition(snake[i - 1].getPosition());
                }
                snake[0].setPosition(sf::Vector2f(snake[0].getPosition().x - x, snake[0].getPosition().y));
            }
            break;
        case 4:
            /*if (snake[0].getPosition() == apple.getPosition()) {
                tails++;
            }*/
            if (snake[0].getPosition().y <= 0) {
                for (int i = tails - 1; i > 0; i--) {
                    snake[i].setPosition(snake[i - 1].getPosition());
                }
                snake[0].setPosition(sf::Vector2f(snake[0].getPosition().x, windowY - y));
            }
            else {
                for (int i = tails - 1; i > 0; i--) {
                    snake[i].setPosition(snake[i - 1].getPosition());
                }
                snake[0].setPosition(sf::Vector2f(snake[0].getPosition().x, snake[0].getPosition().y - y));
            }break;
        default:
            break;
        }
        clock.restart();
    }
}

void Snake::setWindow(sf::RenderWindow& window) {
    windowX = window.getSize().x;
    windowY = window.getSize().y;
}

sf::RectangleShape Snake::getSnake(int i){
    return snake[i];
}

int Snake::getTails() {
    return tails;
}

int Snake::getSpeed() {
    return speed;
}

void Snake::increaseTails() {
    tails++;
}