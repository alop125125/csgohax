#include "Aimbot.h"
#include "enums.h"

//#include <iostream>
//using namespace std;

Aimbot aimbot;


#define LEFTCLICK 0x1
#define LEFTALT 0x12

//TODO add get set functions for these
Aimbot::Aimbot()
{
	//init values
	m_iTarget = -1;
	m_flBest = 999999.0f;


	m_iVirualKey = LEFTALT;
	m_iSmooth = 75;
	m_iBone = BoneID::Head;	
	m_flMaxFov = 75.0f;

	m_bAimbotRCS = true;
	m_bAimbot = true;
}


Aimbot::~Aimbot()
{
}

#pragma region NormalAimbotStuff
void Aimbot::FindTarget()
{
	float tmp; //store current postition

	DropTarget(); //reset values

	for (int i = 0; i < 65; i++)
	{
		if (isGoodTarget(i)) //make sure valid and in fov
		{
			if (m_bAimbot) //if on
			{
				//set tmp to dist from cross to curr player bone
				tmp = Math::GetFov(Math::V2toV3(engine.GetViewAngles()), LocalEntity.GetEyePos(), EntityList[i].GetBonePos(m_iBone));			
				//if its smaller set best and target to be current
				if (tmp < m_flBest)
				{
					m_flBest = tmp;
					m_iTarget = i;
				}
				
			}
		}
	}
}

void Aimbot::GotoTarget()
{
	//check if pressing key and its on
	//while loop instead of for to keep from flickering and not insta locking next target
	while (GetAsyncKeyState(m_iVirualKey) & 0x8000 && m_bAimbot)
	{
		if (m_iTarget == -1)
			return;


		Entity Ent = EntityList[m_iTarget]; //convienence 

											//get necessary information
		fVector3 EnemyPos = Ent.GetBonePos(m_iBone);
		fVector3 LocalPos = LocalEntity.GetEyePos();

		//compensate for velocity
		VelocityComp(EnemyPos, Ent.GetVelocity());

		//calculate vector between me and enemy
		fVector3 Calcd = Math::CalcAngle(LocalPos, EnemyPos);

		//smooth said angle
		fVector3 Smoothed = Math::Smooth(Calcd, Math::V2toV3(engine.GetViewAngles()), m_iSmooth);
		if (!Ent.isDead())
		{
			engine.SetViewAngles(Math::V3toV2(Smoothed));//set view angle to the smoothed one
		}
	}

}

bool Aimbot::isGoodTarget(int iIndex)
{
	if (!EntityList[iIndex].isValid())
		return false;
	if (EntityList[iIndex].GetTeam() == LocalEntity.GetTeam())
		return false;
	if (Math::GetFov(Math::V2toV3(engine.GetViewAngles()), LocalEntity.GetEyePos(), EntityList[iIndex].GetBonePos(m_iBone)) > m_flMaxFov)
		return false;
	return true;
}

void Aimbot::DropTarget()
{
	m_flBest = 99999.f;
	m_iTarget = -1;
}

void Aimbot::VelocityComp(fVector3& EnemyPos, fVector3 EnemyVecVelocity)
{
	EnemyPos = EnemyPos + (EnemyVecVelocity * 0.045f);
	EnemyPos = EnemyPos - (LocalEntity.GetVelocity() * 0.045f);

}

void Aimbot::ApplyRcsToAimAngle(fVector3* pAngle)
{
	if (!m_bAimbotRCS)
		return;
	if (LocalEntity.GetShotsFired() > 0)
	{
		fVector3 Punch = mem.Read<fVector3>(LocalEntity.GetBase() + off.m_aimPunchAngle);
		fVector2 Fin;

		Fin.x = Punch.x * 1.99f;
		Fin.y = Punch.y * 1.99f;

		pAngle->x -= Fin.x;
		pAngle->y -= Fin.y + 0.04f;
	}
}
#pragma endregion

#pragma region Set/Get
int Aimbot::GetBone()
{

}

int Aimbot::GetSmooth()
{

}

int Aimbot::GetMaxFov()
{

}

bool Aimbot::GetAimbot()
{

}

bool Aimbot::GetAimbotRCS()
{

}

void Aimbot::SetBone(int newBone)
{

}

void Aimbot::SetSmooth(int newSmooth)
{

}

void Aimbot::SetMaxFov(int newFov)
{

}

void Aimbot::SetAimbot(bool State)
{

}

void Aimbot::SetAimbotRCS(bool State)
{

}

void Aimbot::SetKey(int VirtualKey)
{

}
#pragma endregion