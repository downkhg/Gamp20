#pragma once
#include "pch.h"

class EffectManager;
class SkillManager;
class Player;

class GameManager
{
public:
	enum E_STAGE { EXIT = -1, CRATE, IVNETORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };

	void Init();

	void Release();
	void EventCreate(CString name, Status status);
	void EventInvetory();
	void EventShop();
	void EventTown();
	void EventFiled();
	void EventBattle();

	void Update();

	int GetStage();
private:
	int m_eStage = E_STAGE::CRATE;

	EffectManager m_cEffectManager;
	SkillManager* m_pSkillManager;
	ItemManager m_cItemManager;
	Player m_cPlayer;
	Player m_cMonster;
	Player m_cShop;
};