#pragma once
#include "Memory.h"
#include "offsets.h"

class Engine
{
public:
	Engine(Memory* memory, DWORD EngineDllBase, offset* Offset);
	~Engine();



private:
	Memory* mem;
	DWORD EngineBase;
	DWORD ClientStateBase;
	offset* off;
};

