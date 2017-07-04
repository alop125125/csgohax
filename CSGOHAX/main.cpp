#include "Memory.h"
#include "offsets.h"
#include <iostream>

using namespace std;

int main()
{
	Memory mem;
	mem.AttachProcess("csgo.exe");
	DWORD Client = mem.FindModuleBase("client.dll");

	DWORD LocalPlayer = mem.Read<DWORD>(Client + offset::dwLocalPlayer);

	while (true)
	{
		int hp = mem.Read<int>(LocalPlayer + offset::m_iHealth);
		cout << hp << endl;
		Sleep(100);
		
	}
}