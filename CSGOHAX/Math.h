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
};

fVector2 fVector3To2(fVector3* const vec);

