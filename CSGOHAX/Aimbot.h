#pragma once
#include "Memory.h"
#include "Engine.h"
#include "Entity.h"
#include "enums.h"

class Aimbot
{
public:
	Aimbot();
	~Aimbot();

	void FindTarget();
	void GotoTarget();

private:
	void DropTarget();

	int m_iTarget = -1;
	int m_iBest;

	bool m_bAimbot;

	float m_flSmooth;

};

extern Aimbot aimbot;