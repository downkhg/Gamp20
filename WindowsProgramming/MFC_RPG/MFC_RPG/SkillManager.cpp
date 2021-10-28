#include "pch.h"

using namespace std;

void Skill::AddEffect(Effect * effect)
{
	m_listEffect.push_back(effect);
}

void Skill::Ative(Player& caster, Player& target)
{
	for (int i = 0; i < m_listEffect.size(); i++)
	{
		m_listEffect[i]->Use(caster, target);
	}
}

SkillManager::SkillManager(EffectManager* pEffectManager)
{
	Skill* pHill = new Skill();
	pHill->AddEffect(pEffectManager->GetEffect(0));
	AddSkill(pHill);
}

SkillManager::~SkillManager()
{
	for (int i = 0; i < m_listSkill.size(); i++)
	{
		Skill* pSkill = m_listSkill[i];
		delete pSkill;
	}
	m_listSkill.clear();
}

void SkillManager::AddSkill(Skill* skill)
{
	m_listSkill.push_back(skill);
}