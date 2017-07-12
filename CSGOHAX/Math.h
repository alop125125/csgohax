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
};

class Math
{
public:
	Math();
	~Math();
	static fVector2 ClampAngles(fVector2 AngleToNormalize);
};

