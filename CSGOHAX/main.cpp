#include <iostream>
#include "Memory.h"
#include "LocalPlayer.h"
#include "offsets.h"
#include "Math.h"

using namespace std;



int main()
{
	offset off;

	Memory mem;
	mem.AttachProcess("csgo.exe");

	DWORD ClientDll = mem.FindModuleBase("client.dll");
	DWORD EngineDLL = mem.FindModuleBase("engine.dll");

	LocalPlayer Player(&mem, ClientDll, &off);

	DWORD ClientState = mem.Read<DWORD>(EngineDLL + off.dwClientState);
	while (true)
	{
		fVector3 view = mem.Read<fVector3>(ClientState + off.dwClientState_ViewAngles);
		
		Sleep(1000);
	}

	Sleep(1);
	
}