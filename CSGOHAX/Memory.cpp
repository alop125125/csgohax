#include "Memory.h"


Memory::Memory()
	:
	isAttach(false)
{
}


Memory::~Memory()
{
}

void Memory::AttachProcess(const char* name)
{
	
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 ProcEntry;
	ProcEntry.dwSize = sizeof(ProcEntry);

	do
		{ 
			
			if (!strcmp(ProcEntry.szExeFile, name))
			{
				ProcID = ProcEntry.th32ProcessID;
				CloseHandle(hPID);
				hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcID);
				isAttach = true;

				return;
			}
		}
	while (Process32Next(hPID, &ProcEntry));

	MessageBox(NULL, "No Good Process Found", "ERRROROROOROR", MB_OKCANCEL);
	system("pause");
	exit(0);
}

DWORD Memory::FindModuleBase(const char* name)
{
	HANDLE hMID = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcID);
	MODULEENTRY32 ModEntry;
	ModEntry.dwSize = sizeof(ModEntry);

	do
	{
		
		if (!strcmp(ModEntry.szModule, name))
		{
			CloseHandle(hMID);
			return (DWORD)ModEntry.modBaseAddr;
		}
	} while (Module32Next(hMID, &ModEntry));
	
	MessageBox(NULL, "No Good Modules Found", "ERRROROROOROR", MB_OKCANCEL);
	system("pause");
	exit(0);

}