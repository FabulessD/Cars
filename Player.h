#ifndef _PLAYER_H_
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include "Unit.h"

class Player: public Unit
{
	int visible;
	Texture pTexture;
	Vector2f Position;
	RectangleShape shape;
	float moveSpeed = 10.f;

public:

	static int health;

	Player(std::string imgDirectory);
	~Player();
	
	FloatRect getPosition();
	RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void update();
	void editPosition();
	void drawPlayer(sf::RenderWindow& window);
	int visibility();
	void setVisibility();
	bool isAlive();
	void ImmortalTexture(std::string imgDriectory);


};

#endif 