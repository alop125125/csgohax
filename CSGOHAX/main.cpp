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

	LocalEntity.Update(INDEX_LOCAL);

	for (int i = 0; i < 65; i++)
	{
		EntityList[i].Update(i);
	}

	while (true)
	{
		fVector3 loc = { 0,0,0 };
		for (int i = 0; i < 65; i++)
		{
			if (EntityList[i].isValid() && LocalEntity.GetTeam() != EntityList[i].GetTeam())
			{
				loc = EntityList[i].GetOrigin();
				//cout << loc << endl;
			}
		}

		if (loc.isZero())
			continue;

		fVector3 Lock = Math::CalcAngle(LocalEntity.GetOrigin(), loc);
		fVector3 Clamp = Math::ClampAngles(Lock);

		if (GetAsyncKeyState(VK_MENU))
		{
			en.SetViewAngles(Math::V3toV2(Clamp));
		}
		

		Sleep(100);
	
	}
	
}