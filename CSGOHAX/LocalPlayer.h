#pragma once
#include "Memory.h"
#include "offsets.h"

class LocalPlayer
{
public:
	LocalPlayer(Memory* memory, DWORD ClientDLLBase, offset* Offset);
	~LocalPlayer();

	DWORD GetPlayerBase();
	int GetHealth();
	int GetTeam();

private:
	DWORD ClientBase;
	Memory* mem;
	DWORD LocalPlayerBase;
	offset* off;
};

