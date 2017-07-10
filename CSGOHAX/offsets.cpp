#include "offsets.h"

offset::offset()
	:
	cfg(new ConfigFile("offsets.cfg"))
{
	m_iHealth = cfg->getValueOfKey<DWORD>("m_iHealth");
	dwLocalPlayer = cfg->getValueOfKey<DWORD>("dwLocalPlayer");
	dwClientState = cfg->getValueOfKey<DWORD>("dwClientState");
	dwClientState_ViewAngles = cfg->getValueOfKey<DWORD>("dwClientState_ViewAngles");
}

offset::~offset()
{

}

