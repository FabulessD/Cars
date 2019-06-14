#include "Obstacle.h"
#include <ctime>

Obstacle::Obstacle(std::string imgDirectory) : Unit(Vector2f(0.f, 0.f))
{
	Position.x = 180.f;
	Position.y = 200.f;
	pTexture.loadFromFile(imgDirectory);
	pTexture.setSmooth(true);
	shape.setSize(Vector2f(92, 196));
	shape.setTexture(&pTexture);
}

Obstacle::Obstacle(std::string imgDirectory, int a) : Unit(Vector2f(0.f, 0.f))
{

	if (a == 0)
	{
	Position.x = 440.f;
	Position.y = 0.f;
	}
	else if (a == 1)
	{
	Position.x = 180.f;
	Position.y = -800.f;
	}
	else if (a == 2)
	{
	Position.x = 300.f;
	Position.y = -600.f;
	}
	else if (a == 3)
	{
		Position.x = 570.f;
		Position.y = -400.f;
	}
		pTexture.loadFromFile(imgDirectory);
		pTexture.setSmooth(true);
		shape.setSize(Vector2f(92, 196));
		shape.setTexture(&pTexture);
		
}


void Obstacle::move()
{
	Position.y += 0.03f;
}

void Obstacle::update()
{
	this->move();
	shape.setPosition(Position);
}

void Obstacle::drawObstacle(sf::RenderWindow& window)
{
	window.draw(shape);
}

FloatRect Obstacle::getPosition()
{
	return shape.getGlobalBounds();
}

RectangleShape Obstacle::getShape()
{
	return shape;
}

float Obstacle::ret_position_y()
{
	return Position.y;
}

void Obstacle::Reset(int a)
{
		Position.y = -300.f;
		int los = a;
		if (los == 0)
			Position.x = 440.f;
		else if (los == 1)
			Position.x = 180.f;
		else if (los == 2)
			Position.x = 570.f;
		else if (los == 3)
			Position.x = 300.f;
		else
			Position.x = 180.f;
}

bool Obstacle::operator==(const Obstacle& o)const
{
	if (this->Position.x == o.Position.x and this->Position.y == o.Position.y)
		return true;
	return false;
}

