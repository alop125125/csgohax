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

	LocalEntity.Update(INDEX_LOCAL);

	while (true)
	{
		cout << LocalEntity.GetHealth() << endl;
		
		Sleep(100);
		

	}
	
	
	
	
}