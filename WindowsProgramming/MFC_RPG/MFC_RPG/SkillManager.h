#pragma once
#include <vector>
using namespace std;

class Player;
class Effect;
class EffectManager;

class Skill
{
	vector<Effect*> m_listEffect;
public:
	void AddEffect(Effect* effect);
	virtual void Ative(Player& caster, Player& Target);
};

class SkillManager
{
	vector<Skill*> m_listSkill;
public:
	SkillManager(EffectManager* pEffectManager);
	~SkillManager();
	void AddSkill(Skill* skill);
	Skill* GetSkill(int idx) { return m_listSkill[idx]; }
};