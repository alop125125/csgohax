#include <iostream>
#include "Memory.h"
#include "offsets.h"
#include "Math.h"
#include "Engine.h"
#include "Entity.h"
#include "Aimbot.h"
#include <thread>
#include "UI.h"


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
	while(true)
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
	while (!engine.isIngame())
		Sleep(100);
	this_thread::sleep_for(chrono::milliseconds(500));
	ui->draw();
	while (true)
	{

		if (GetAsyncKeyState(0x26))//up
		{
			ui->Selection_UP();
		}

		if (GetAsyncKeyState(0x28))//down
		{
			ui->Selection_DOWN();
		}

		if (GetAsyncKeyState(0x25))//left
		{
			ui->Selection_LEFT();
		}

		if (GetAsyncKeyState(0x27))//right
		{
			ui->Selection_RIGHT();
		}
		this_thread::sleep_for(chrono::milliseconds(78));
	}
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
	thread tGUI(GUILoop);
	tGUI.detach();
	thread tUpdate(Update);
	tUpdate.detach();
	thread tAimbot(AimbotLoop);
	tAimbot.detach();
	for (;;) { Sleep(1000); }
	
	
	return 0;
}