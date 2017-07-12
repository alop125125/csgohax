#include "LocalPlayer.h"


LocalPlayer::LocalPlayer(Memory* memory, DWORD ClientDLLBase, offset* Offset)
	:
	mem(memory),
	ClientBase(ClientDLLBase),
	off(Offset)	
{
	LocalPlayerBase = mem->Read<DWORD>(ClientBase + off->dwLocalPlayer);
}


LocalPlayer::~LocalPlayer()
{
	
}

DWORD LocalPlayer::GetPlayerBase()
{
	return LocalPlayerBase;
}

int LocalPlayer::GetHealth()
{
	int Health = mem->Read<int>(LocalPlayerBase + off->m_iHealth);
	return Health;
	
}

int LocalPlayer::GetTeam()
{
	int Team = mem->Read<int>(LocalPlayerBase + off->m_iHealth);
}