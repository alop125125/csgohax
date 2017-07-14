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

bool Entity::Update(int iIndex)//CURRENTLY RETURNED FALSE AFTER JOINING NEW GAME
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

	dwBoneMatrix = mem.Read<DWORD>(Ent + off.m_dwBoneMatrix);

	//m_iCompetitiveRanking; //process->Read<int>( g_pStatic->GameResources + g_pDynamic->m_iCompetitiveRanking + m_iIndex * 4 );
	//m_iCompetitiveWins;   //process->Read<int>( g_pStatic->GameResources + g_pDynamic->m_iCompetitiveWins + m_iIndex * 4 );


	return true;
}

fVector3 Entity::GetOrigin()
{
	m_vOrigin = mem.Read<fVector3>(Ent + off.m_vecOrigin);
	return m_vOrigin;
}

fVector3 Entity::GetVelocity()
{
	m_vVelocity = mem.Read<fVector3>(Ent + off.m_vecVelocity);
	return m_vVelocity;
}

fVector3 Entity::GetBonePos(int iBone)
{
	fVector3 ret;
	ret.x = mem.Read<float>(dwBoneMatrix + 0x30 * iBone + 0x0c);
	ret.y = mem.Read<float>(dwBoneMatrix + 0x30 * iBone + 0x1c);
	ret.z = mem.Read<float>(dwBoneMatrix + 0x30 * iBone + 0x2c);
	return ret;
}

int Entity::GetTeam()
{
	m_iTeamNum = mem.Read<int>(Ent + off.m_iTeamNum);
	return m_iTeamNum;
}


int Entity::GetHealth()
{
	m_iHealth = mem.Read<int>(Ent + off.m_iHealth);
	return m_iHealth;
}

int Entity::GetFlags()
{
	m_iFlags = mem.Read<int>(Ent + off.m_fFlags);
	return m_iFlags;
}

int Entity::GetCrosshairId()
{
	m_iCrosshairID = mem.Read<int>(Ent + off.m_iCrosshairId);
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
	if (isImmune())
		return false;

	return true;
}


bool Entity::isDead()
{
	m_bDead = mem.Read<bool>(Ent + off.m_lifeState);
	return m_bDead;
}

bool Entity::isDormant()
{
	m_bIsDormant = mem.Read<bool>(Ent + 0xE9);
	return m_bIsDormant;
}

bool Entity::isImmune()
{
	m_bIsImmune = mem.Read<bool>(Ent + off.m_bGunGameImmunity);
	return m_bIsImmune;
}

fVector3 Entity::GetEyePos()
{
	m_vEye = GetOrigin() + mem.Read<fVector3>(Ent + off.m_vecViewOffset);
	return m_vEye;
}