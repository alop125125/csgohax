#include <iostream>
#include "Memory.h"
#include "offsets.h"
#include "Math.h"
#include "Engine.h"
#include "Entity.h"

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

	//LocalPlayer Player(&mem, ClientDll, &off);
	Engine en(EngineDLL);
	
	DWORD LocalPlayer = mem.Read<DWORD>(ClientDll + off.dwLocalPlayer);

	
	for (int i = 0; i < 65; i++)
	{
		EntityList[i].Update(i);
	}

	while (true)
	{
		LocalEntity.Update(INDEX_LOCAL);
		/*for (int i = 0; i < 65; i++)
		{
			bool isCont = EntityList[i].isValid();
			if (isCont)
				cout << EntityList[i].GetHealth() << endl;	
		}*/

		int CH = LocalEntity.GetCrosshairId() - 1;
		if (CH < 0)
		{
			Sleep(100);
			continue;
		}
		if (EntityList[CH].isValid())
			cout << EntityList[CH].GetHealth() << endl;

		Sleep(100);
	
	}
	
}