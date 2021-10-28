#pragma once
#include <vector>

class Player;
class Skill;
class Effect;

using namespace std;

class Effect
{
public:
	virtual void Use(Player& caster, Player& Target) = 0;
};

class HillEffect : public Effect
{
public:
	void Use(Player& caster, Player& Target);
};

class EffectManager
{
	vector<Effect*> m_listEffect;
public:
	void Init();
	void Release();
	void AddEffect(Effect* effect);
	Effect* GetEffect(int idx);
};