#pragma once
#include <iostream>
#include "Aimbot.h"

class UI
{
public:
	UI();
	~UI();
	
	const enum FeaturesAndSettings
	{
		bAimbot = 0,
		bAimbotRCS
	};
	
	void draw();
	void Selection_UP();
	void Selection_DOWN();
	void Selection_RIGHT();
	void Selection_LEFT();

	void clampSelection();

	int m_iCurrSelection;
	HANDLE hConsole;


private:
	void color_green();
	void color_white();
	
	int m_iNumberFeatures;
};

extern UI* ui;