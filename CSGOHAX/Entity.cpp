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

	return true;
}
//
//DWORD_PTR Entity::GetPointer()
//{
//
//}
//
//DWORD_PTR Entity::GetLocalPointer()
//{
//
//}
//
//fVector3 Entity::GetOrigin()
//{
//
//}
//fVector3 Entity::GetVelocity()
//{
//
//}
//
//int Entity::GetTeam()
//{
//
//}
int Entity::GetHealth()
{
	return m_iHealth;
}
//int Entity::GetFlags()
//{
//
//}
//int Entity::GetCrosshairId()
//{
//
//}
//int Entity::GetActiveWeapon()
//{
//
//}
//
//float Entity::GetFlashDuration()
//{
//
//}
//
//void Entity::SetFlashDuration()
//{
//
//}
//
//bool Entity::isValid()
//{
//
//}
//
//bool Entity::isDead()
//{
//
//}
//
//bool Entity::isDormant()
//{
//
//}