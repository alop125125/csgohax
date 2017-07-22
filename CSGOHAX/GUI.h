#pragma once
#include "ImGui\imgui.h"
#include "imgui_impl_dx9.h"
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

class GUI
{
public:
	GUI();
	~GUI();

	bool Init();
	void Run();


private:
	bool InitWindow();
	bool InitD3D();
	void HandleGUI();
	void EndGUI();

private:
	const wchar_t* CLASS_NAME = _T("Basic Class");
	WNDCLASSEX wc;
	wchar_t* Caption;
	HWND hwnd;
	int x, y, width, height;
	ImVec4 clear_col;
};

extern GUI* g_pGui;