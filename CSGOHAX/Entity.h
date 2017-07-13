#pragma once
#include "Memory.h"
#include "offsets.h"
#include "Math.h"

#define INDEX_LOCAL 883

class Entity
{
public:
	Entity();
	~Entity();

	bool Update(int iIndex);

	fVector3 GetOrigin();
	fVector3 GetVelocity();


	int GetTeam();
	int GetHealth();
	int GetFlags();
	int GetCrosshairId();
	int GetActiveWeapon();
	//TODO bool isActiveWeaponPistol


	float GetFlashDuration();
	void SetFlashDuration();

	bool isValid();
	bool isDead();
	bool isDormant();
	bool isImmune();

private:
	DWORD ClientBase;

	int m_iIndex;

	fVector3 m_vOrigin;
	fVector3 m_vVelocity;
	
	DWORD Ent;
	
	int m_iTeamNum;
	int m_iHealth;
	int m_iFlags;
	int m_iCrosshairID;
	int m_iWeaponId;

	int m_iCompetitiveRanking;
	int m_iCompetitiveWins;

	float m_flFlashDuration;
	
	bool m_bDead;
	bool m_bIsDormant;
	bool m_bIsImmune;

};

extern Entity LocalEntity;
extern Entity EntityList[65];
