#pragma once
#include <Windows.h>
#include <TlHelp32.h>

using namespace std;

class Memory
{
public:
	//public member functions
	Memory();
	~Memory();
	bool AttachProcess(const char* name);
	DWORD FindModuleBase(const char* name);

	DWORD GetClient();
	DWORD GetEngine();

private:
	//private member variables
	DWORD m_dwProcID;
	HANDLE hProc;

	DWORD ClientBase;
	DWORD EngineBase;

public:
	//reading memory function
	//in header cause template is pain
	template <class T>
	T Read(DWORD dwAddress)
	{
		T ret;
		ReadProcessMemory(hProc, (LPVOID)dwAddress, &ret, sizeof(T), NULL);
		return ret;
	}
	//override read for offset (this is never used dunno why i made it)
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
	//write memory function
	template <class T>
	void Write(DWORD dwAddress, T value)
	{
		WriteProcessMemory(hProc, (LPVOID)dwAddress, &value, sizeof(T), 0);
	}

};

extern Memory mem; //global memory object

