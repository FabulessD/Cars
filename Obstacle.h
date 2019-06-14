#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include <SFML/Graphics.hpp>
#include "Unit.h"

class Obstacle: public Unit
{
	Vector2f Position;
	RectangleShape shape;
	Texture pTexture;
public:
//	Vector2f Position;
	explicit Obstacle(std::string imgDirectory);
	Obstacle(std::string imgDirectory, int a);
	~Obstacle() {};
	void move();
	void update();
	void drawObstacle(sf::RenderWindow& window);
	void Reset(int a);
	bool operator==(const Obstacle& o)const;
	FloatRect getPosition();
	RectangleShape getShape();
	Obstacle& operator++();
	float ret_position_y();
};

#endif _OBSTACLE_H_