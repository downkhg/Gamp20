#pragma once
#include <iostream>
#include <vector>
#include <afx.h>


using namespace std;

class Skill;
class Effect;
class Item;

struct Status {
	int nHP;
	int nMP;
	int nStr;
	int nInt;
	int nDef;

	Status(int _hp = 0, int _mp = 0, int _str = 0, int _int = 0, int _def = 0)
	{
		nHP = _hp;
		nMP = _mp;
		nStr = _str;
		nInt = _int;
		nDef = _def;
	}
	void operator+=(const int value)
	{
		this->nHP += value;
		this->nMP += value;
		this->nStr += value;
		this->nDef += value;
		this->nInt += value;
	}
	Status operator+(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP + status.nHP;
		sResult.nMP = nMP + status.nMP;
		sResult.nStr = nStr + status.nStr;
		sResult.nDef = nDef + status.nDef;
		sResult.nInt = nInt + status.nInt;
		return sResult;
	}
	Status operator-(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP - status.nHP;
		sResult.nMP = nMP - status.nMP;
		sResult.nStr = nStr - status.nStr;
		sResult.nDef = nDef - status.nDef;
		sResult.nInt = nInt - status.nInt;
		return sResult;
	}
	void Show()
	{
		cout << "HP:" << nHP << endl;
		cout << "MP:" << nMP << endl;
		cout << "STR:" << nStr << endl;
		cout << "INT:" << nInt << endl;
		cout << "DEF:" << nDef << endl;
	}
};

class Player {
	CString m_strName;
	Status m_sStatus;
	int m_nLv;
	int m_nExp;
	int m_nGold;

	vector<Item*> m_listIventory;
	vector<Item*> m_listEqument;
	vector<Skill*> m_listSkills;
public:
	Player();

	CString& GetName() { return m_strName; }
	Status& GetStatus() { return m_sStatus; };
	int GetLv() { return m_nLv; };
	int GetExp() { return m_nExp; };
	int GetGold() { return m_nGold; };

	void AddSkill(Skill* skill);

	void ActiveSkill(int idx, Player& target);

	void SetIventory(Item* item);
	Item* GetIventoryIdx(int idx);
	void DeleteIventory(int idx);

	bool UseItem(int idx);

	void ReleaseEqument(int idx);

	void Set(CString strName, int _hp, int _mp, int _str, int _int, int _def, int _exp);
	void Set(CString strName, Status status, int _exp);
	void Attack(Player& taget);
	void StillItem(Player& taget);
	bool Buy(Player& target, int idx);
	void Sell(int idx);
	bool LvUp();

	bool Dead();

	void Show();
};