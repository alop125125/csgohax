#pragma once
#include "Memory.h"
#include "offsets.h"
#include "Math.h"

class Engine
{
public:
	Engine(Memory* memory, DWORD EngineDllBase, offset* Offset);
	~Engine();

	bool isIngame();
	fVector2 GetViewAngles();
	void SetViewAngles(fVector2 Angle);
	void SetViewAngles(float x, float y);
private:
	Memory* mem;
	DWORD EngineBase;
	DWORD ClientStateBase;
	offset* off;
};

