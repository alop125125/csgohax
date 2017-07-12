#include "Entity.h"

Entity LocalEntity;
Entity EntityList[65];

Entity::Entity()
{

	m_iIndex = NULL;

	m_iTeamNum = NULL;
	m_iHealth = NULL;
	m_iFlags = NULL;


	m_bDead = true;
}


Entity::~Entity()
{
}

bool Entity::Update(int iIndex)
{
	ClientBase = mem.GetClient();

	m_iIndex = iIndex;
	if (!m_iIndex)
		return false;
	if (m_iIndex < 0)
		return false;

	if (m_iIndex == INDEX_LOCAL)
	{
		Ent = mem.Read<DWORD>(ClientBase + off.dwLocalPlayer);
		
	}
	else
	{
		Ent = mem.Read<DWORD>(ClientBase + off.dwEntityList + m_iIndex * 0x10);
	}

	if (!Ent)
		return false;

	

	m_iHealth = mem.Read<int>(Ent + off.m_iHealth);
	m_vOrigin = mem.Read<fVector3>(Ent + off.m_vecOrigin);
	m_vVelocity = mem.Read<fVector3>(Ent + off.m_vecVelocity);

	m_iTeamNum = mem.Read<int>(Ent + off.m_iTeamNum);
	m_iFlags = mem.Read<int>(Ent + off.m_fFlags);
	m_iCrosshairID = mem.Read<int>(Ent + off.m_iCrosshairId);
	m_hActiveWeapon = mem.Read<int>(Ent + off.m_hActiveWeapon);
	

	m_iCompetitiveRanking; //process->Read<int>( g_pStatic->GameResources + g_pDynamic->m_iCompetitiveRanking + m_iIndex * 4 );
	m_iCompetitiveWins;   //process->Read<int>( g_pStatic->GameResources + g_pDynamic->m_iCompetitiveWins + m_iIndex * 4 );

	m_flFlashDuration;

	m_bDead = mem.Read<bool>(Ent + off.m_lifeState);
	m_bIsDormant = mem.Read<bool>(Ent + 0xE9);

	return true;
}

fVector3 Entity::GetOrigin()
{
	return m_vOrigin;
}

fVector3 Entity::GetVelocity()
{
	return m_vVelocity;
}

int Entity::GetTeam()
{
	return m_iTeamNum;
}

int Entity::GetHealth()
{
	return m_iHealth;
}

int Entity::GetFlags()
{
	return m_iFlags;
}

int Entity::GetCrosshairId()
{
	return m_iCrosshairID;
}

int Entity::GetActiveWeapon()
{
	int weaponId = mem.Read<int>(Ent + 0x12C0);
	if (weaponId > 50 || weaponId < 0)
		weaponId = 42;

	return weaponId;
}

float Entity::GetFlashDuration()
{
	m_flFlashDuration = mem.Read<float>(Ent + off.m_flFlashDuration);
	return m_flFlashDuration;
}

void Entity::SetFlashDuration()
{
	mem.Write<float>(Ent + off.m_flFlashDuration, 0.0f);
}

bool Entity::isValid()
{
	if (!GetTeam())
		return false;

	if (isDead())
		return false;

	if (isDormant())
		return false;

	if (GetOrigin().isZero())
		return false;

	if (GetHealth() < 1)
		return false;

	return true;
}


bool Entity::isDead()
{
	return m_bDead;
}

bool Entity::isDormant()
{
	return m_bIsDormant;
}