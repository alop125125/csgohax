#include "Aimbot.h"

Aimbot aimbot;

Aimbot::Aimbot()
{
	m_iTarget = -1;
	m_flBest = 999999.0f;
	m_bAimbot = true;
	m_flSmooth = 1.0f;
	m_iBone = BoneList::BONE_HEAD;
}


Aimbot::~Aimbot()
{
}

void Aimbot::FindTarget()
{
	for (int i = 0; i < 65; i++) //aimbot.cpp line 96
	{
		if (EntityList[i].isValid() && LocalEntity.GetTeam() != EntityList[i].GetTeam())
		{
			if (m_bAimbot)
			{
				m_iTarget = i;
			}
		}
	}
}

void Aimbot::GotoTarget()
{
	if (GetAsyncKeyState(0x01) && m_bAimbot)
	{
		if (m_iTarget == -1)
			return;

		Entity Ent = EntityList[m_iTarget];

		fVector3 EnemyPos = Ent.GetOrigin();
		fVector3 LocalPos = LocalEntity.GetOrigin();

		fVector3 Calcd = Math::CalcAngle(LocalPos, EnemyPos);
		fVector3 Clampd = Math::ClampAngles(Calcd);

		engine.SetViewAngles(Math::V3toV2(Clampd));
		
	}
}

void Aimbot::DropTarget()
{

}