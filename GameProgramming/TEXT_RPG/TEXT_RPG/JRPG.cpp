#include <iostream>
#include <string>
using namespace std;

class Player {
	string m_strName;

	int m_nHP;
	int m_nMP;
	int m_nStr;
	int m_nInt;
	int m_nDef;
public:
	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def)
	{
		m_strName = strName;
		m_nHP = _hp;
		m_nMP = _mp;
		m_nStr = _str;
		m_nInt = _int;
		m_nDef = _def;
	}

	void Attack(Player& target)
	{
		target.Demaged(m_nStr);
	}
	void Demaged(int dem)
	{
		m_nHP -= dem - m_nDef;
	}
	bool Dead()
	{
		if(m_nHP <= 0)
			return true;
		return false;
	}

	void Show()
	{
		cout <<"######### "<< m_strName << "######### " << endl;
		cout << "HP:" << m_nHP << endl;
		cout << "MP:" << m_nMP << endl;
		cout << "STR:" << m_nStr << endl;
		cout << "INT:" << m_nInt << endl;
		cout << "DEF:" << m_nDef << endl;
	}
};

void main()
{
	Player cPlayer;
	Player cMonster;

	cPlayer.Set("Player",100,100,20,10,10);
	cMonster.Set("Slime",100, 100, 20, 10, 10);

	//전투는 언제끝나는가? -> 몬스터나 플레이어 중 하나라도 죽으면 끝남.
	//->죽은것은? -> HP가 0보다 작을때 -> 만약 HP가 0보다 작다면 죽음.
	while ( !(cPlayer.Dead() || cMonster.Dead()) )
	{
		if (cPlayer.Dead() == false)
			cPlayer.Attack(cMonster);
		cMonster.Show();
		if (cMonster.Dead() == false)
			cMonster.Attack(cPlayer);
		cPlayer.Show();
	}
}