#pragma once
#include <Windows.h>
#include <iostream>

struct fVector2
{
	float x;
	float y;
};

struct fVector3
{
	float x;
	float y;
	float z;
};

class Math
{
public:
	Math();
	~Math();
	static fVector2 ClampAngles(fVector2 AngleToNormalize);
};

