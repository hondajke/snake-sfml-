#ifndef __SNAKE_H__
#include <SFML/Graphics.hpp>
#include <stdio.h>

class Snake{
private:
	int direction = 1; //Direction from 1 to 4/1 -right/2 - bottom/3 - left/4 - up
	float speed = 0.1; //Speed of snake(Increasing when he eat apple)
	int tails = 2; //Tails increasing when snake eat the apple
	int windowX;
	int windowY;
	int x = 20; //
	int	y = 20; //size of snake
	sf::Clock clock;
	std::vector<sf::RectangleShape> snake;
public:
	void setDirection(sf::Event events);
	void increaseSpeed();
	int getSpeed();
	void increaseTails();
	int getTails();
	void update();
	void initSnake();
	void setWindow(sf::RenderWindow& window);
	sf::RectangleShape getSnake(int i);
};
#endif // !__SNAKE_H__