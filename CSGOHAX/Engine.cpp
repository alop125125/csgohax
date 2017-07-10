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
