#include <iostream>
#include "Memory.h"
#include "offsets.h"
#include "Math.h"
#include "Engine.h"
#include "Entity.h"
#include "Aimbot.h"
#include <thread>
#include "GUI.h"

//------------------------------------------------------------------------
//-------------- _____ ------------------------------- _____ -------------
//--------------|  ___|-------------------------------|  ___|-------------
//--------------| |__   ___   ___   __ _  _ __    ___ | |__  -------------
//--------------|  __| / __| / __| / _` || '_ \  / _ \|  __| -------------
//--------------| |___ \__ \| (__ | (_| || |_) ||  __/| |___ -------------
//--------------\____/ |___/ \___| \__,_|| .__/  \___|\____/--------------
//---------------------------------------| |------------------------------
//---------------------------------------|_|------------------------------            
//------------------------------------------------------------------------

using namespace std;

//overload vectors
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

//every second updates
void Update()
{
	for (;;)
	{
		if (!engine.isIngame())
			continue;
		
		LocalEntity.Update(INDEX_LOCAL);

		//update enitities
		for (int i = 0; i < 65; i++)
		{
			EntityList[i].Update(i);
		}
		
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

//runs GUI
void GUILoop()
{
	g_pGui->Init();
	g_pGui->Run();
}

//runs aimbot
void AimbotLoop()
{
	while (true)
	{
		if (engine.isIngame())
		{
			aimbot.FindTarget();
			aimbot.GotoTarget();	
			this_thread::sleep_for(chrono::milliseconds(1));
		}
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}


int main()
{
	//attach csgo.exe
	if (!mem.AttachProcess(L"csgo.exe"))
		return false;

	//find needed info
	DWORD ClientDll = mem.FindModuleBase(L"client.dll");
	DWORD EngineDLL = mem.FindModuleBase(L"engine.dll");

	//setup engine
	engine.setup();

	//if not in game loop till you are 
	while (!engine.isIngame())
	{
		Sleep(1);
	}

	

	//run threads
	thread tUpdate(Update);
	tUpdate.detach();
	thread tAimbot(AimbotLoop);
	tAimbot.detach();
	thread tGUI(GUILoop);
	tGUI.join();
	
	
	return 0;
}