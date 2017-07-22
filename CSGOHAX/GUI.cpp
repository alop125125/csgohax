#include "GUI.h"

GUI* g_pGui = new GUI;

static LPDIRECT3DDEVICE9 g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS g_d3dpp;

extern LRESULT ImGui_ImplDX9_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplDX9_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


GUI::GUI()
{
	hwnd = NULL;
	Caption = _T("BAD CHEAT BAD GUI");
	x = 0;
	y = 0;
	width = 400;
	height = 400;
	clear_col = ImColor(75, 25, 12);
}


GUI::~GUI()
{
}

bool GUI::Init()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	if (!InitWindow())
		return false;
	if (!InitD3D())
		return false;

	return true;
}

bool GUI::InitWindow()
{
	wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, LoadCursor(NULL, IDC_ARROW), NULL, NULL, CLASS_NAME, NULL };
	RegisterClassEx(&wc);
	hwnd = CreateWindow(CLASS_NAME, Caption, WS_VISIBLE | WS_POPUP | WS_MAXIMIZEBOX, x, y, width, height, NULL, NULL, wc.hInstance, NULL);
	if (!hwnd)
		return false;
	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);
	return true;
}

bool GUI::InitD3D()
{
	LPDIRECT3D9 pD3D;
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		UnregisterClass(CLASS_NAME, wc.hInstance);
		return false;
	}

	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
	{
		pD3D->Release();
		UnregisterClass(CLASS_NAME, wc.hInstance);
		return false;
	}

	ImGui_ImplDX9_Init(hwnd, g_pd3dDevice);

	return true;
}

void GUI::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}
		ImGui_ImplDX9_NewFrame();
		HandleGUI();

	}
}

void GUI::HandleGUI()
{
	ImGuiWindowFlags wndFlags = 0;
	wndFlags |= ImGuiWindowFlags_NoResize;
	wndFlags |= ImGuiWindowFlags_NoMove;
	wndFlags |= ImGuiWindowFlags_NoCollapse;

	ImGui::SetNextWindowSize(ImVec2((float)width, (float)height), ImGuiSetCond_Always);
	ImGui::SetNextWindowPos(ImVec2((float)0, (float)0), ImGuiSetCond_Always);

	ImGui::Begin("Main Menu", 0, wndFlags);

	if (ImGui::Button("Exit"))
		PostQuitMessage(0);

	ImGui::End();

	EndGUI();
}

void GUI::EndGUI()
{
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_col.x*255.0f), (int)(clear_col.y*255.0f), (int)(clear_col.z*255.0f), (int)(clear_col.w*255.0f));
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
	if (g_pd3dDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		g_pd3dDevice->EndScene();
	}
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}