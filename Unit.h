#ifndef UNIT_H_
#define UNIT_H_

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


class Unit
{
protected:
	Vector2f StartPosition;
public:
	Unit(Vector2f startP);
	~Unit() {};
	Vector2f ReturnStartPosition()const;
	virtual void update() = 0;

};

#endif  UNIT_H_ 