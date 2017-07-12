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

	DWORD GetClient();
	DWORD GetEngine();
private:
	DWORD ProcID;
	HANDLE hProc;

	DWORD ClientBase;
	DWORD EngineBase;

public:
	template <class T>
	T Read(DWORD dwAddress)
	{
		T ret;
		ReadProcessMemory(hProc, (LPVOID)dwAddress, &ret, sizeof(T), NULL);
		return ret;
	}
	template <class T>
	T Read(DWORD dwAddress, DWORD Offset)
	{
		DWORD base;
		ReadProcessMemory(hProc, (LPVOID)dwAddress, &base, sizeof(T), NULL);

		DWORD AddrOff = base + Offset;
		T returned;
		ReadProcessMemory(hProc, (LPVOID)AddrOff, &returned, sizeof(T), NULL);
		return returned;
	}

	template <class T>
	void Write(DWORD dwAddress, T value)
	{
		WriteProcessMemory(hProc, (LPVOID)dwAddress, &value, sizeof(T), 0);
	}


public:
	bool isAttach;
};

extern Memory mem;

