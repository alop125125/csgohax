#pragma once
#include "Memory.h"
#include "Engine.h"
#include "Entity.h"

class Aimbot
{
public:
	Aimbot();
	~Aimbot();

	void ApplyRcsToAimAngle(fVector3* pAngle);

	void FindTarget();
	void GotoTarget();

private:
	void DropTarget();
	bool isGoodTarget(int iIndex);
	void VelocityComp(fVector3& EnemyPos, fVector3 EnemyVecVelocity, fVector3 PlayerVecVelocity);

private:
	int m_iTarget;
	float m_flBest;

	//Settings
	int m_iVirualKey;
	
	int m_iBone;
	int m_iSmooth;
	
	float m_flMaxFov;

private:
	//Features
	bool m_bAimbot;
};

extern Aimbot aimbot; //global variable for using aimbot