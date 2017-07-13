#include "Math.h"


Math::Math()
{
}


Math::~Math()
{
}

fVector3 Math::CalcAngle(fVector3 FirstAngle, fVector3 SecondAngle)
{
	fVector3 AimAngles;
	fVector3 delta = FirstAngle - SecondAngle;
	float hyp = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	AimAngles.x = atanf(delta.z / hyp) * 57.295779513082f;
	AimAngles.y = atanf(delta.y / delta.x) * 57.295779513082f;
	AimAngles.z = 0.0f;
	if (delta.x >= 0.0)
		AimAngles.y += 180.0f;

	return AimAngles;
}

fVector2 Math::V3toV2(fVector3 Angle)
{
	fVector2 ret;
	ret.x = Angle.x;
	ret.y = Angle.y;
	return ret;
}

fVector3 Math::V2toV3(fVector2 Angle)
{
	fVector3 ret;
	ret.x = Angle.x;
	ret.y = Angle.y;
	ret.z = 0.f;
	return ret;
}

fVector2 Math::ClampAngles(fVector2 AngleToNormalize)
{
	fVector2 vec = AngleToNormalize;
	if (vec.x > 89.0f && vec.x <= 180.0f)
	{
		vec.x = 89.0f;
	}
	while (vec.x > 180.f)
	{
		vec.x -= 360.f;
	}
	while (vec.x < -89.0f)
	{
		vec.x = -89.0f;
	}
	while (vec.y > 180.f)
	{
		vec.y -= 360.f;
	}
	while (vec.y < -180.f)
	{
		vec.y += 360.f;
	}
	return vec;
}


fVector3 Math::ClampAngles(fVector3 AngleToNormalize)
{
	fVector3 vec = AngleToNormalize;
	if (vec.x > 89.0f && vec.x <= 180.0f)
	{
		vec.x = 89.0f;
	}
	while (vec.x > 180.f)
	{
		vec.x -= 360.f;
	}
	while (vec.x < -89.0f)
	{
		vec.x = -89.0f;
	}
	while (vec.y > 180.f)
	{
		vec.y -= 360.f;
	}
	while (vec.y < -180.f)
	{
		vec.y += 360.f;
	}

	return vec;
}