#pragma once

#include <iostream>
#include "Player.h"
#include <afx.h>

using namespace std;

class Item {
public:
	enum E_ITEM_KIND { WEAPON, ARMOR, ACC, POTION, THROW };
	E_ITEM_KIND eItemKind;
	CString strName;
	CString strComment;
	Status sFuction;
	int nGold;
	Item(E_ITEM_KIND kind = THROW, CString name = _T("none"), CString comment = _T("none"), Status status = Status(), int gold = 0)
	{
		Set(kind, name, comment, status, gold);
	}
	void Set(E_ITEM_KIND kind, CString name, CString comment, Status status, int gold)
	{
		eItemKind = kind;
		strName = name;
		strComment = comment;
		sFuction = status;
		nGold = gold;
	}
};

class ItemManager {
	vector<Item> m_listItems;
public:
	enum E_ITEM_LIST { WOOD_SOWRD, BONE_SOWRD, WOOD_ARMOR, BONE_AMROR, WOOD_RING, BONE_RING, HP_POTION, MP_POTION, STONE, BOOM };
	ItemManager();
	void SaveFile();
	void LoadFile();
	Item* GetItem(int idx);
};