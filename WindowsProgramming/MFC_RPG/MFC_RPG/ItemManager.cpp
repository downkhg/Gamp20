#include "pch.h"

using namespace std;

ItemManager::ItemManager()
{
	m_listItems.resize(10);
	m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, _T("목검"), _T("데미지증가"), Status(0, 0, 10, 0, 0), 100);
	m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, _T("본소드"), _T("데미지증가"), Status(0, 0, 20, 0, 0), 100);
	m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, _T("나무갑옷"), _T("방어력증가"), Status(0, 0, 0, 10, 0), 100);
	m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, _T("본아머"), _T("방어력증가"), Status(0, 0, 0, 20, 0), 100);
	m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, _T("나무반지"), _T("체력증가"), Status(10,0,0,0,0), 100);
	m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, _T("해골반지"), _T("체력증가"), Status(20, 0, 0, 0, 0), 100);
	m_listItems[6] = Item(Item::E_ITEM_KIND::POTION, _T("힐링포션"), _T("HP회복"), Status(100, 0, 0, 0, 0), 100);
	m_listItems[7] = Item(Item::E_ITEM_KIND::POTION, _T("마나포션"), _T("MP회복"), Status(0,100, 0, 0, 0), 100);
	m_listItems[8] = Item(Item::E_ITEM_KIND::THROW, _T("짱돌"), _T("단일적대미지"), Status(0, 0, 50, 0, 0), 100);
	m_listItems[9] = Item(Item::E_ITEM_KIND::THROW, _T("목검"), _T("다수적대미지"), Status(0, 0, 50, 0, 0), 100);
	//SaveFile();
	//LoadFile();
}

Item* ItemManager::GetItem(int idx)
{
	return &m_listItems[idx];
}