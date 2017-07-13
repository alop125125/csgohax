#include "Math.h"
#define DEG2RAD( x  )  ( (float)(x) * (float)( M_PI_F / 180.f ) )
#define RAD2DEG( x  )  ( (float)(x) * (float)( 180.f/M_PI_F ) )

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
void Math::MakeVector( fVector3 angle, fVector3& vector )
{
	float pitch = float( angle.x * M_PI / 180 );
	float yaw = float( angle.y * M_PI / 180 );
	float tmp = float( cos( pitch ) );
	vector.x = float( -tmp * -cos( yaw ) );
	vector.y = float( sin( yaw )*tmp );
	vector.z = float( -sin( pitch ) );
}



float Math::radianToDeg(float rad)
{
	return (rad * M_PI / 180);
}

float Dot(const fVector3 &v1, fVector3 &v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float Math::GetFov(fVector3 angle, fVector3 src, fVector3 dst)
{
	fVector3 ang, aim;
	ang = CalcAngle(src, dst);
	MakeVector(angle, aim);
	MakeVector(ang, ang);

	float mag = sqrt(pow(aim.x, 2) + pow(aim.y, 2) + pow(aim.z, 2));
	float u_dot_v = Dot(aim, ang);
	
	return RAD2DEG(acos(u_dot_v / (pow(mag, 2))));
}