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
	void VelocityComp(fVector3& EnemyPos, fVector3 EnemyVecVelocity);

private:
	int m_iTarget;
	float m_flBest;


public:
	//Settings
	int m_iVirualKey;
	
	int m_iBone;
	int m_iSmooth;
	
	float m_flMaxFov;
	float m_flRCSAmount;
public:
	//Features
	bool m_bAimbot;
	bool m_bAimbotRCS;

public:
	int GetBone();
	int GetSmooth();
	float GetMaxFov();
	float GetRCSAmount();
	bool GetAimbot();
	bool GetAimbotRCS();

	void SetRCSAmount(float newAmount);
	void SetBone(int newBone);
	void SetSmooth(int newSmooth);
	void SetMaxFov(float newFov);
	void SetAimbot(bool State);
	void SetAimbotRCS(bool State);
	void SetKey(int VirtualKey);


};

extern Aimbot aimbot; //global variable for using aimbot