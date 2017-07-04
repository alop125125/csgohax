#pragma once
#include <Windows.h>
#include <TlHelp32.h>

using namespace std;

class Memory
{
public:
	Memory();
	~Memory();
	void AttachProcess(const char* name);
	DWORD FindModuleBase(const char* name);

private:
	DWORD ProcID;
	HANDLE hProc;

public:
	template <class T>
	T Read(DWORD dwAddress)
	{
		T ret;
		ReadProcessMemory(hProc, (LPVOID)dwAddress, &ret, sizeof(T), NULL);
		return ret;
	}
};

