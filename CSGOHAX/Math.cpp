#include "Math.h"

Math::Math()
{
}


Math::~Math()
{
}

fVector2 fVector3To2(fVector3* const vec)
{
	fVector2 returnVec;
	returnVec.x = vec->x;
	returnVec.y = vec->y;
	return returnVec;
}