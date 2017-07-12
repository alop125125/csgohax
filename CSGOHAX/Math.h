#pragma once
#include <Windows.h>
#include <iostream>

struct fVector2
{
	float x;
	float y;
	fVector2 operator+(fVector2 const& vec)
	{
		x += vec.x;
		y += vec.y;
		return *this;
	}
};

struct fVector3
{
	float x;
	float y;
	float z;

	fVector3 operator+(fVector3 const& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}
	bool isZero()
	{
		if (x == 0.f && y == 0.f && z == 0.f)
			return true;
		else
			return false;
	}
};

class Math
{
public:
	Math();
	~Math();
	static fVector2 ClampAngles(fVector2 AngleToNormalize);
};

