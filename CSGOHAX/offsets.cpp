#include "offsets.h"

offset::offset()
	:
	cfg(new ConfigFile("offsets.cfg"))
{
	m_iHealth = cfg->getValueOfKey<DWORD>("m_iHealth");
	dwLocalPlayer = cfg->getValueOfKey<DWORD>("dwLocalPlayer");
}

offset::~offset()
{

}

