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
		
		int flags = mem.Read<int>(LocalPlayer + offset::m_fFlags);
		//cout << flags << endl;
		if (GetAsyncKeyState(0x20))
		{
			if (flags == 257 || flags == 263)
			{
				keybd_event(MapVirtualKey(0x20,0), 0x39, KEYEVENTF_EXTENDEDKEY, 0);
				keybd_event(MapVirtualKey(0x20,0), 0x39, KEYEVENTF_KEYUP, 0);
				Sleep(1);
			}
		}
		
		Sleep(1);
	}
}