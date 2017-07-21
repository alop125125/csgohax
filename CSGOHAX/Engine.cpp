#include "Engine.h"

Engine engine;

Engine::Engine()
{
	
}


Engine::~Engine()
{
}


void Engine::setup()
{
	EngineBase = mem.GetEngine();
	ClientStateBase = mem.Read<DWORD>(EngineBase + off.dwClientState);
}

bool Engine::isIngame()
{
	int state = mem.Read<int>(ClientStateBase + off.dwClientState_State);
	if (state == 6)
		return true;
	else
		return false;
}

int Engine::GetState()
{
	int state = mem.Read<int>(ClientStateBase + off.dwClientState_State);
	return state;
}

fVector2 Engine::GetViewAngles()
{
	return mem.Read<fVector2>(ClientStateBase + off.dwClientState_ViewAngles);
}

void Engine::SetViewAngles(fVector2 Angle)
{
	mem.Write<fVector2>(ClientStateBase + off.dwClientState_ViewAngles, Angle);
}

void Engine::SetViewAngles(float x, float y)
{
	fVector2 Angle = { x,y };
	fVector2 Clamped = Math::ClampAngles(Angle);
	mem.Write<fVector2>(ClientStateBase + off.dwClientState_ViewAngles, Clamped);
}