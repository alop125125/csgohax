#include "UI.h"

using namespace std;

UI* ui = new UI();

UI::UI()
	:
	m_iCurrSelection(0),
	hConsole(GetStdHandle(STD_OUTPUT_HANDLE)),
	m_iNumberFeatures(2)
{
}


UI::~UI()
{
}


void UI::Selection_UP()
{
	m_iCurrSelection--;
	this->draw();
}

void UI::Selection_DOWN()
{
	m_iCurrSelection++;
	this->draw();
}

void UI::Selection_RIGHT()
{
	switch(m_iCurrSelection)
	{
	case FeaturesAndSettings::bAimbot:
		aimbot.SetAimbot(!aimbot.GetAimbot());
		break;
	case FeaturesAndSettings::bAimbotRCS:
		aimbot.SetAimbotRCS(!aimbot.GetAimbotRCS());
		break;
	default:
		this->clampSelection();
		this->Selection_RIGHT();
		break;
	}
	this->draw();
}

void UI::Selection_LEFT()
{

	this->draw();
}

void UI::color_green()
{
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void UI::color_white()
{
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void UI::clampSelection()
{
	if (m_iCurrSelection < 0)
		m_iCurrSelection = (m_iNumberFeatures - 1);
	if (m_iCurrSelection > (m_iNumberFeatures - 1))
		m_iCurrSelection = 0;
}

void UI::draw()
{
	this->clampSelection();
	system("cls");
	if (m_iCurrSelection == FeaturesAndSettings::bAimbot)
		this->color_green();
	cout << "Aimbot: \t" << aimbot.GetAimbot() << endl;
	this->color_white();
	if (m_iCurrSelection == FeaturesAndSettings::bAimbotRCS)
		this->color_green();
	cout << "AimbotRCS: \t" << aimbot.GetAimbotRCS() << endl;
	this->color_white();
}


