#include "Player.h"
#include <iostream>

int Player::health = 3;

Player::Player(std::string imgDirectory) : Unit(Vector2f(370.f, 550.f))
{
	visible = 0;
	Position.x = StartPosition.x;
	Position.y = StartPosition.y;
	pTexture.loadFromFile(imgDirectory);
	pTexture.setSmooth(true);
	shape.setSize(Vector2f(92, 196));
	shape.setTexture(&pTexture);
	shape.setPosition(StartPosition);
}

Player::~Player()
{
	
}


void Player::drawPlayer(sf::RenderWindow& window)
{
	window.draw(shape);
}

FloatRect Player::getPosition()
{
	return shape.getGlobalBounds();
}

RectangleShape Player::getShape()
{
	return shape;
}

void Player::moveRight()
{
	if (Position.x < 600)
	Position.x += moveSpeed;
}

void Player::moveLeft()
{
	if(Position.x > 150)
	Position.x -= moveSpeed;
}

void Player::update()
{
	shape.setPosition(Position);
}


void Player::editPosition() 
{
	Position.x = StartPosition.x;
	Position.y = StartPosition.y;
	health -= 1;
	visible = 0;
	std::cout << health << "hp left." << std::endl;
}

int Player::visibility()
{
	return visible;
}

void Player::setVisibility()
{
	visible = 1;
}

bool Player::isAlive()
{
	if (health <= 0)
	return false;
	return true;
}

void Player::ImmortalTexture(std::string imgDirectory)
{
	pTexture.loadFromFile(imgDirectory);
	pTexture.setSmooth(true);
	shape.setTexture(&pTexture);
}
