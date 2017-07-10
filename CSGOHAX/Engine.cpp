#include "Engine.h"



Engine::Engine(Memory* memory, DWORD EngineDllBase, offset* Offset)
	:
	mem(memory),
	EngineBase(EngineDllBase),
	off(Offset)
{
	ClientStateBase = mem->Read<DWORD>(EngineBase + off->dwClientState);
}


Engine::~Engine()
{
}


bool Engine::isIngame()
{
	int state = mem->Read<int>(ClientStateBase + off->dwClientState_State);
	if (state == 6)
		return true;
	else
		return false;
}

fVector2 Engine::GetViewAngles()
{
	return mem->Read<fVector2>(ClientStateBase + off->dwClientState_ViewAngles);
}

void Engine::SetViewAngles(fVector2 Angle)
{
	mem->Write<fVector2>(ClientStateBase + off->dwClientState_ViewAngles, Angle);
}

void Engine::SetViewAngles(float x, float y)
{
	fVector2 Angle = { x,y };
	fVector2 Clamped = Math::ClampAngles(Angle);
	mem->Write<fVector2>(ClientStateBase + off->dwClientState_ViewAngles, Clamped);
}