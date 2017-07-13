#include <iostream>
#include "Memory.h"
#include "offsets.h"
#include "Math.h"
#include "Engine.h"
#include "Entity.h"
#include "Aimbot.h"

using namespace std;

ostream& operator<<(ostream& os, const fVector2& vec)
{
	os << "{" << vec.x << "," << vec.y << "}";
	return os;
}
ostream& operator<<(ostream& os, const fVector3& vec)
{
	os << "{" << vec.x << ", " << vec.y << ", " << vec.z << "}";
	return os;
}

int main()
{
	mem.AttachProcess("csgo.exe");

	DWORD ClientDll = mem.FindModuleBase("client.dll");
	DWORD EngineDLL = mem.FindModuleBase("engine.dll");

	
	engine.setup();
	LocalEntity.Update(INDEX_LOCAL);

	for (int i = 0; i < 65; i++)
	{
		EntityList[i].Update(i);
	}

	while (true)
	{
		aimbot.FindTarget();
		aimbot.GotoTarget();
		
		

		Sleep(10);
	
	}
	
}