#include "Unit.h"

Unit::Unit(Vector2f startP): StartPosition(startP)
{
}
Vector2f Unit::ReturnStartPosition() const
{
	return StartPosition;
}
