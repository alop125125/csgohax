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

	int m_iTarget;
	int m_iBone;

	bool m_bAimbot;

	float m_flSmooth;
	float m_flBest;

};

extern Aimbot aimbot;