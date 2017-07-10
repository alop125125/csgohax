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
		cout << en.GetViewAngles() << endl;

		if (GetAsyncKeyState(VK_INSERT) && en.isIngame())
		{
			en.SetViewAngles(0.f,0.f);
		}
		Sleep(100);
	}

	Sleep(1);
	
}