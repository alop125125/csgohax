#include "offsets.h"

offset::offset()
	:
	cfg(new ConfigFile("offsets.cfg"))
{
	m_iHealth = cfg->getValueOfKey<DWORD>("m_iHealth");
	dwLocalPlayer = cfg->getValueOfKey<DWORD>("dwLocalPlayer");
	dwClientState = cfg->getValueOfKey<DWORD>("dwClientState");
	dwClientState_ViewAngles = cfg->getValueOfKey<DWORD>("dwClientState_ViewAngles");
	dwClientState_State = cfg->getValueOfKey<DWORD>("dwClientState_State");
	m_vecOrigin = cfg->getValueOfKey<DWORD>("m_vecOrigin");
	m_iTeamNum = cfg->getValueOfKey<DWORD>("m_iTeamNum");
	m_iCrosshairId = cfg->getValueOfKey<DWORD>("m_iCrosshairId");
	dwEntityList = cfg->getValueOfKey<DWORD>("dwEntityList");
	m_fFlags = cfg->getValueOfKey<DWORD>("m_fFlags");
}

offset::~offset()
{

}

