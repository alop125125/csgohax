#pragma once
#include "Memory.h"
#include "Engine.h"
#include "Entity.h"

class Aimbot
{
public:
	Aimbot();
	~Aimbot();

	void FindTarget();
	void GotoTarget();

private:
	void DropTarget();

private:
	//declarations
	int m_iVirualKey;

	int m_iTarget;
	int m_iBone;
	int m_iSmooth;

	bool m_bAimbot;

	float m_flBest;
	float m_flFov;
};

extern Aimbot aimbot; //global variable for using aimbot