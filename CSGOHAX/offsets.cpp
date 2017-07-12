#include "offsets.h"

offset off;

offset::offset()
	:
	cfg(new ConfigFile("offsets.cfg"))
{
	m_ArmorValue = cfg->getValueOfKey<DWORD>("m_ArmorValue");
	m_Collision = cfg->getValueOfKey<DWORD>("m_Collision ");
	m_CollisionGroup = cfg->getValueOfKey<DWORD>("m_CollisionGroup");
	m_Local = cfg->getValueOfKey<DWORD>("m_Local");
	m_MoveType = cfg->getValueOfKey<DWORD>("m_MoveType");
	m_OriginalOwnerXuidHigh = cfg->getValueOfKey<DWORD>("m_OriginalOwnerXuidHigh");
	m_OriginalOwnerXuidLow = cfg->getValueOfKey<DWORD>("m_OriginalOwnerXuidLow");
	m_aimPunchAngle = cfg->getValueOfKey<DWORD>("m_aimPunchAngle");
	m_aimPunchAngleVel = cfg->getValueOfKey<DWORD>("m_aimPunchAngleVel");
	m_bGunGameImmunity = cfg->getValueOfKey<DWORD>("m_bGunGameImmunity");
	m_bHasDefuser = cfg->getValueOfKey<DWORD>("m_bHasDefuser");
	m_bHasHelmet = cfg->getValueOfKey<DWORD>("m_bHasHelmet");
	m_bInReload = cfg->getValueOfKey<DWORD>("m_bInReload");
	m_bIsDefusing = cfg->getValueOfKey<DWORD>("m_bIsDefusing");
	m_bIsScoped = cfg->getValueOfKey<DWORD>("m_bIsScoped");
	m_bSpotted = cfg->getValueOfKey<DWORD>("m_bSpotted");
	m_bSpottedByMask = cfg->getValueOfKey<DWORD>("m_bSpottedByMask");
	m_dwBoneMatrix = cfg->getValueOfKey<DWORD>("m_dwBoneMatrix");
	m_fAccuracyPenalty = cfg->getValueOfKey<DWORD>("m_fAccuracyPenalty");
	m_fFlags = cfg->getValueOfKey<DWORD>("m_fFlags");
	m_flFallbackWear = cfg->getValueOfKey<DWORD>("m_flFallbackWear");
	m_flFlashDuration = cfg->getValueOfKey<DWORD>("m_flFlashDuration");
	m_flFlashMaxAlpha = cfg->getValueOfKey<DWORD>("m_flFlashMaxAlpha");
	m_flNextPrimaryAttack = cfg->getValueOfKey<DWORD>("m_flNextPrimaryAttack");
	m_hActiveWeapon = cfg->getValueOfKey<DWORD>("m_hActiveWeapon");
	m_hMyWeapons = cfg->getValueOfKey<DWORD>("m_hMyWeapons");
	m_hObserverTarget = cfg->getValueOfKey<DWORD>("m_hObserverTarget");
	m_hOwner = cfg->getValueOfKey<DWORD>("m_hOwner");
	m_hOwnerEntity = cfg->getValueOfKey<DWORD>("m_hOwnerEntity");
	m_iAccountID = cfg->getValueOfKey<DWORD>("m_iAccountID");
	m_iClip1 = cfg->getValueOfKey<DWORD>("m_iClip1");
	m_iCompetitiveRanking = cfg->getValueOfKey<DWORD>("m_iCompetitiveRanking");
	m_iCompetitiveWins = cfg->getValueOfKey<DWORD>("m_iCompetitiveWins");
	m_iCrosshairId = cfg->getValueOfKey<DWORD>("m_iCrosshairId");
	m_iEntityQuality = cfg->getValueOfKey<DWORD>("m_iEntityQuality");
	m_iFOVStart = cfg->getValueOfKey<DWORD>("m_iFOVStart");
	m_iGlowIndex = cfg->getValueOfKey<DWORD>("m_iGlowIndex");
	m_iHealth = cfg->getValueOfKey<DWORD>("m_iHealth");
	m_iItemDefinitionIndex = cfg->getValueOfKey<DWORD>("m_iItemDefinitionIndex");
	m_iItemIDHigh = cfg->getValueOfKey<DWORD>("m_iItemIDHigh");
	m_iObserverMode = cfg->getValueOfKey<DWORD>("m_iObserverMode");
	m_iShotsFired = cfg->getValueOfKey<DWORD>("m_iShotsFired");
	m_iState = cfg->getValueOfKey<DWORD>("m_iState");
	m_iTeamNum = cfg->getValueOfKey<DWORD>("m_iTeamNum");
	m_lifeState = cfg->getValueOfKey<DWORD>("m_lifeState");
	m_nFallbackPaintKit = cfg->getValueOfKey<DWORD>("m_nFallbackPaintKit");
	m_nFallbackSeed = cfg->getValueOfKey<DWORD>("m_nFallbackSeed");
	m_nFallbackStatTrak = cfg->getValueOfKey<DWORD>("m_nFallbackStatTrak");
	m_nForceBone = cfg->getValueOfKey<DWORD>("m_nForceBone");
	m_nTickBase = cfg->getValueOfKey<DWORD>("m_nTickBase");
	m_rgflCoordinateFrame = cfg->getValueOfKey<DWORD>("m_rgflCoordinateFrame");
	m_szCustomName = cfg->getValueOfKey<DWORD>("m_szCustomName");
	m_szLastPlaceName = cfg->getValueOfKey<DWORD>("m_szLastPlaceName");
	m_vecOrigin = cfg->getValueOfKey<DWORD>("m_vecOrigin");
	m_vecVelocity = cfg->getValueOfKey<DWORD>("m_vecVelocity");
	m_vecViewOffset = cfg->getValueOfKey<DWORD>("m_vecViewOffset");
	m_viewPunchAngle = cfg->getValueOfKey<DWORD>("m_viewPunchAngle");
	dwClientState = cfg->getValueOfKey<DWORD>("dwClientState");
	dwClientState_GetLocalPlayer = cfg->getValueOfKey<DWORD>("dwClientState_GetLocalPlayer");
	dwClientState_Map = cfg->getValueOfKey<DWORD>("dwClientState_Map");
	dwClientState_MapDirectory = cfg->getValueOfKey<DWORD>("dwClientState_MapDirectory");
	dwClientState_MaxPlayer = cfg->getValueOfKey<DWORD>("dwClientState_MaxPlayer");
	dwClientState_PlayerInfo = cfg->getValueOfKey<DWORD>("dwClientState_PlayerInfo");
	dwClientState_State = cfg->getValueOfKey<DWORD>("dwClientState_State");
	dwClientState_ViewAngles = cfg->getValueOfKey<DWORD>("dwClientState_ViewAngles");
	dwClientState_IsHLTV = cfg->getValueOfKey<DWORD>("dwClientState_IsHLTV");
	dwEntityList = cfg->getValueOfKey<DWORD>("dwEntityList");
	dwForceAttack = cfg->getValueOfKey<DWORD>("dwForceAttack");
	dwForceAttack2 = cfg->getValueOfKey<DWORD>("dwForceAttack2");
	dwForceBackward = cfg->getValueOfKey<DWORD>("dwForceBackward");
	dwForceForward = cfg->getValueOfKey<DWORD>("dwForceForward");
	dwForceJump = cfg->getValueOfKey<DWORD>("dwForceJump");
	dwForceLeft = cfg->getValueOfKey<DWORD>("dwForceLeft");
	dwForceRight = cfg->getValueOfKey<DWORD>("dwForceRight");
	dwGameDir = cfg->getValueOfKey<DWORD>("dwGameDir");
	dwGameRulesProxy = cfg->getValueOfKey<DWORD>("dwGameRulesProxy");
	dwGetAllClasses = cfg->getValueOfKey<DWORD>("dwGetAllClasses");
	dwGlobalVars = cfg->getValueOfKey<DWORD>("dwGlobalVars");
	dwGlowObjectManager = cfg->getValueOfKey<DWORD>("dwGlowObjectManager");
	dwInput = cfg->getValueOfKey<DWORD>("dwInput");
	dwInterfaceLinkList = cfg->getValueOfKey<DWORD>("dwInterfaceLinkList");
	dwLocalPlayer = cfg->getValueOfKey<DWORD>("dwLocalPlayer");
	dwMouseEnable = cfg->getValueOfKey<DWORD>("dwMouseEnable");
	dwMouseEnablePtr = cfg->getValueOfKey<DWORD>("dwMouseEnablePtr");
	dwPlayerResource = cfg->getValueOfKey<DWORD>("dwPlayerResource");
	dwRadarBase = cfg->getValueOfKey<DWORD>("dwRadarBase");
	dwSensitivity = cfg->getValueOfKey<DWORD>("dwSensitivity");
	dwSensitivityPtr = cfg->getValueOfKey<DWORD>("dwSensitivityPtr");
	dwViewMatrix = cfg->getValueOfKey<DWORD>("dwViewMatrix");
	dwWeaponTable = cfg->getValueOfKey<DWORD>("dwWeaponTable");
	dwWeaponTableIndex = cfg->getValueOfKey<DWORD>("dwWeaponTableIndex");
	dwYawPtr = cfg->getValueOfKey<DWORD>("dwYawPtr");
	dwZoomSensitivityRatioPtr = cfg->getValueOfKey<DWORD>("dwZoomSensitivityRatioPtr");
	dwbSendPackets = cfg->getValueOfKey<DWORD>("dwbSendPackets");
	dwppDirect3DDevice9 = cfg->getValueOfKey<DWORD>("dwppDirect3DDevice9");
	dwSetClanTag = cfg->getValueOfKey<DWORD>("dwSetClanTag");
	m_pStudioHdr = cfg->getValueOfKey<DWORD>("m_pStudioHdr");
}

offset::~offset()
{
	delete cfg;
}

