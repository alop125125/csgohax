#include "Aimbot.h"

#include <iostream>
using namespace std;

Aimbot aimbot;

Aimbot::Aimbot()
{
	m_iTarget = -1;
	m_flBest = 999999.0f;
	m_bAimbot = true;
	m_flSmooth = 1.0f;
	m_iBone = 8;
}


Aimbot::~Aimbot()
{
}

void Aimbot::FindTarget()
{
	float tmp;
	DropTarget();
	for (int i = 0; i < 65; i++) //aimbot.cpp line 96
	{
		if (EntityList[i].isValid() && LocalEntity.GetTeam() != EntityList[i].GetTeam())
		{
			if (m_bAimbot)
			{
				tmp = Math::GetFov(Math::V2toV3(engine.GetViewAngles()), LocalEntity.GetEyePos(), EntityList[i].GetBonePos(m_iBone));			
				if (tmp < m_flBest)
				{
					m_flBest = tmp;
					m_iTarget = i;
				}
				//cout << "Currect Dist: " << tmp << "   Number: " << i <<
				//	"\t\t Best Dist " << m_flBest << "   Best Num" << m_iTarget << endl;
				//system("cls");
			}
		}
	}
}

void Aimbot::GotoTarget()
{
	if (GetAsyncKeyState(0x12) & 0x8000 && m_bAimbot)
	{
		if (m_iTarget == -1)
			return;

		Entity Ent = EntityList[m_iTarget];

		
		fVector3 EnemyPos = Ent.GetBonePos(m_iBone);
		fVector3 LocalPos = LocalEntity.GetEyePos();
		

		fVector3 Calcd = Math::CalcAngle(LocalPos, EnemyPos);
		fVector3 Clampd = Math::ClampAngles(Calcd);


		engine.SetViewAngles(Math::V3toV2(Clampd));
		Sleep(100);
	}
	
}

void Aimbot::DropTarget()
{
	m_flBest = 99999.f;
	m_iTarget = -1;
}