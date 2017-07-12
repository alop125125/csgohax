#include <iostream>
#include "Memory.h"
#include "LocalPlayer.h"
#include "offsets.h"
#include "Math.h"
#include "Engine.h"

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
	offset off;

	Memory mem;
	mem.AttachProcess("csgo.exe");

	DWORD ClientDll = mem.FindModuleBase("client.dll");
	DWORD EngineDLL = mem.FindModuleBase("engine.dll");

	LocalPlayer Player(&mem, ClientDll, &off);
	Engine en(&mem, EngineDLL, &off);
	
	
	
	while (true)
	{
		int CrossHairID = mem.Read<int>(Player.GetPlayerBase() + off.m_iCrosshairId);
		if (CrossHairID > 0 && CrossHairID < 65)
		{
			DWORD EntInCH = mem.Read<DWORD>(ClientDll + off.dwEntityList + (CrossHairID - 1) * 0x10);
			int EntHP = mem.Read<int>(EntInCH + off.m_iHealth);
			cout << EntHP << endl;
		}
		Sleep(100);

	}
	
	
	Sleep(1);
	
}