#include <iostream>
#include "Memory.h"
#include "LocalPlayer.h"
#include "offsets.h"

using namespace std;

int main()
{
	offset off;

	Memory mem;
	mem.AttachProcess("csgo.exe");
	DWORD ClientDll = mem.FindModuleBase("client.dll");
	
	LocalPlayer Player(&mem, ClientDll, &off);

	while (true)
	{
		cout << Player.GetHealth() << endl;
		Sleep(1000);
	}

	Sleep(1);
	
}