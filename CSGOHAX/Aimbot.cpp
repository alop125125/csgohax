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

}

void Aimbot::GotoTarget()
{

}

void Aimbot::DropTarget()
{

}