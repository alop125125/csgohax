#include "Memory.h"

Memory mem;

//init values
Memory::Memory()
{

}


Memory::~Memory()
{
}

//TODO Improve
DWORD Memory::GetClient()
{
	return ClientBase;
}

//TODO Improve
DWORD Memory::GetEngine()
{
	return EngineBase;
}

//stores a handle to the process
bool Memory::AttachProcess(const char* name)
{
	//get snapshot of processes
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 ProcEntry;
	ProcEntry.dwSize = sizeof(ProcEntry);

	//while the current process is not name
	do
		{ 	
			if (!strcmp(ProcEntry.szExeFile, name))
			{
				m_dwProcID = ProcEntry.th32ProcessID; //set proc id
				CloseHandle(hPID); //close handle
				hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_dwProcID);
				return true;
			}
		}
	while (Process32Next(hPID, &ProcEntry));

	return false;
}

//finds the base address of the module specified in the name paramater
DWORD Memory::FindModuleBase(const char* name)
{
	//take snapshot of m_dwProcID's modules
	HANDLE hMID = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_dwProcID);
	MODULEENTRY32 ModEntry;
	ModEntry.dwSize = sizeof(ModEntry);

	//loop till module is equal to name
	do
	{	
		if (!strcmp(ModEntry.szModule, name))
		{

			//Please dont do this just dont
			if (!strcmp(ModEntry.szModule, "client.dll"))
			{
				ClientBase = (DWORD)ModEntry.modBaseAddr;
			}
			if (!strcmp(ModEntry.szModule, "engine.dll"))
			{
				EngineBase = (DWORD)ModEntry.modBaseAddr;
			}


			CloseHandle(hMID);
			return (DWORD)ModEntry.modBaseAddr;
		}
	} while (Module32Next(hMID, &ModEntry));
	
	//if it goes through all and never finds it exit and give message box
	MessageBox(NULL, "Module Not Found", "Error", MB_OK);
	exit(1);
}
