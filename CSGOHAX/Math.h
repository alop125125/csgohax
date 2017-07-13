#pragma once
#include <Windows.h>
#include <iostream>

#define M_PI 3.141592653589793
#define M_PI_F ((float)M_PI)

struct fVector2
{
	float x;
	float y;
	fVector2 operator+(const fVector2& vec)
	{
		x += vec.x;
		y += vec.y;
		return *this;
	}
	bool isZero()
	{
		if (x == 0.f && y == 0.f)
			return true;
		else
			return false;
	}
};

struct fVector3
{
	float x;
	float y;
	float z;

	fVector3& operator+(const fVector3& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}
	fVector3& operator-(const fVector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}
	fVector3& operator=(const fVector2& v)
	{
		x = v.x;
		y = v.y;
		z = 0;

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
	static fVector3 ClampAngles(fVector3 AngleToNormalize);

	static fVector2 V3toV2(fVector3 Angle);
	static fVector3 V2toV3(fVector2 Angle);

	static float radianToDeg(float rad);

	static void MakeVector(fVector3 angle, fVector3& vector);
	static fVector3 CalcAngle(fVector3 FirstAngle, fVector3 SecondAngle);
	static float GetFov(fVector3 angle, fVector3 src, fVector3 dst);
};

