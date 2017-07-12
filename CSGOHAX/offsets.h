#pragma once
#include "Config.h"
typedef unsigned long DWORD;

class offset
{
public:

	offset();
	~offset();


private:
	ConfigFile* cfg;

public:
	DWORD m_ArmorValue;
	DWORD m_Collision;
	DWORD m_CollisionGroup;
	DWORD m_Local;
	DWORD m_MoveType;
	DWORD m_OriginalOwnerXuidHigh;
	DWORD m_OriginalOwnerXuidLow;
	DWORD m_aimPunchAngle;
	DWORD m_aimPunchAngleVel;
	DWORD m_bGunGameImmunity;
	DWORD m_bHasDefuser;
	DWORD m_bHasHelmet;
	DWORD m_bInReload;
	DWORD m_bIsDefusing;
	DWORD m_bIsScoped;
	DWORD m_bSpotted;
	DWORD m_bSpottedByMask;
	DWORD m_dwBoneMatrix;
	DWORD m_fAccuracyPenalty;
	DWORD m_fFlags;
	DWORD m_flFallbackWear;
	DWORD m_flFlashDuration;
	DWORD m_flFlashMaxAlpha;
	DWORD m_flNextPrimaryAttack;
	DWORD m_hActiveWeapon;
	DWORD m_hMyWeapons;
	DWORD m_hObserverTarget;
	DWORD m_hOwner;
	DWORD m_hOwnerEntity;
	DWORD m_iAccountID;
	DWORD m_iClip1;
	DWORD m_iCompetitiveRanking;
	DWORD m_iCompetitiveWins;
	DWORD m_iCrosshairId;
	DWORD m_iEntityQuality;
	DWORD m_iFOVStart;
	DWORD m_iGlowIndex;
	DWORD m_iHealth;
	DWORD m_iItemDefinitionIndex;
	DWORD m_iItemIDHigh;
	DWORD m_iObserverMode;
	DWORD m_iShotsFired;
	DWORD m_iState;
	DWORD m_iTeamNum;
	DWORD m_lifeState;
	DWORD m_nFallbackPaintKit;
	DWORD m_nFallbackSeed;
	DWORD m_nFallbackStatTrak;
	DWORD m_nForceBone;
	DWORD m_nTickBase;
	DWORD m_rgflCoordinateFrame;
	DWORD m_szCustomName;
	DWORD m_szLastPlaceName;
	DWORD m_vecOrigin;
	DWORD m_vecVelocity;
	DWORD m_vecViewOffset;
	DWORD m_viewPunchAngle;
	DWORD dwClientState;
	DWORD dwClientState_GetLocalPlayer;
	DWORD dwClientState_Map;
	DWORD dwClientState_MapDirectory;
	DWORD dwClientState_MaxPlayer;
	DWORD dwClientState_PlayerInfo;
	DWORD dwClientState_State;
	DWORD dwClientState_ViewAngles;
	DWORD dwClientState_IsHLTV;
	DWORD dwEntityList;
	DWORD dwForceAttack;
	DWORD dwForceAttack2;
	DWORD dwForceBackward;
	DWORD dwForceForward;
	DWORD dwForceJump;
	DWORD dwForceLeft;
	DWORD dwForceRight;
	DWORD dwGameDir;
	DWORD dwGameRulesProxy;
	DWORD dwGetAllClasses;
	DWORD dwGlobalVars;
	DWORD dwGlowObjectManager;
	DWORD dwInput;
	DWORD dwInterfaceLinkList;
	DWORD dwLocalPlayer;
	DWORD dwMouseEnable;
	DWORD dwMouseEnablePtr;
	DWORD dwPlayerResource;
	DWORD dwRadarBase;
	DWORD dwSensitivity;
	DWORD dwSensitivityPtr;
	DWORD dwViewMatrix;
	DWORD dwWeaponTable;
	DWORD dwWeaponTableIndex;
	DWORD dwYawPtr;
	DWORD dwZoomSensitivityRatioPtr;
	DWORD dwbSendPackets;
	DWORD dwppDirect3DDevice9;
	DWORD dwSetClanTag;
	DWORD m_pStudioHdr;
};

extern offset off;
