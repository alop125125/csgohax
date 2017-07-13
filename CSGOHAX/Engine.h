#pragma once
#include "Memory.h"
#include "offsets.h"
#include "Math.h"

class Engine
{
public:
	Engine();
	~Engine();


	void setup();
	bool isIngame();

	fVector2 GetViewAngles();
	

	void SetViewAngles(fVector2 Angle);
	void SetViewAngles(float x, float y);

	
private:
	DWORD EngineBase;
	DWORD ClientStateBase;
};

extern Engine engine;