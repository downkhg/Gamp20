#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
	string m_strName;
	Status m_sStatus;
	int m_nLv;
	int m_nExp;

public:
	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp)
	{
		m_strName = strName;
		m_sStatus.nHP = _hp;
		m_sStatus.nMP = _mp;
		m_sStatus.nStr = _str;
		m_sStatus.nInt = _int;
		m_sStatus.nDef = _def;
		m_nExp = _exp;
		m_nLv = 1;
	}

	void Attack(Player& taget)
	{
		taget.m_sStatus.nHP -= m_sStatus.nStr - m_sStatus.nDef;
	}

	void StillItem(Player& taget)
	{
		//Ÿ���� ����ġ�� �����ͼ� �� ����ġ�� �ø���.
		this->m_nExp = taget.m_nExp;
	}

	bool LvUp()
	{
		//���� ����ġ�� 100 �̻�Ǹ�, ����+1, ��� �ɷ�ġ 10����, ����ġ �ʱ�ȭ.
		if (m_nExp >= 100)
		{
			m_sStatus += 10;
			m_nLv++;
			m_nExp -= 100;
			return true;
		}
		return false;
	}

	bool Dead()
	{
		if (m_sStatus.nHP <= 0)
			return true;
		return false;
	}

	void Show()
	{
		cout << "######### " << m_strName << "######### " << endl;
		m_sStatus.Show();
	}
};

void main()
{
	Player cPlayer;
	Player cMonster;

	cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
	//cMonster.SetIventory(Item(Item::E_ITEM_KIND::WEAPON, "���", "������ ����", Status(0, 0, 10), 100));

	//������ ���������°�? -> ���ͳ� �÷��̾� �� �ϳ��� ������ ����.
	//->��������? -> HP�� 0���� ������ -> ���� HP�� 0���� �۴ٸ� ����.
	while (!(cPlayer.Dead() || cMonster.Dead()))
	{
		if (cPlayer.Dead() == false)
			cPlayer.Attack(cMonster);
		cMonster.Show();
		if (cMonster.Dead() == false)
			cMonster.Attack(cPlayer);
		else
		{
			cPlayer.StillItem(cMonster);
			if (cPlayer.LvUp())
				cout << "����!" << endl;
		}

		cPlayer.Show();
	}
}