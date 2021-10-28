#include "pch.h"

using namespace std;

ItemManager::ItemManager()
{
	m_listItems.resize(10);
	m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, _T("���"), _T("����������"), Status(0, 0, 10, 0, 0), 100);
	m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, _T("���ҵ�"), _T("����������"), Status(0, 0, 20, 0, 0), 100);
	m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, _T("��������"), _T("��������"), Status(0, 0, 0, 10, 0), 100);
	m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, _T("���Ƹ�"), _T("��������"), Status(0, 0, 0, 20, 0), 100);
	m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, _T("��������"), _T("ü������"), Status(10,0,0,0,0), 100);
	m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, _T("�ذ����"), _T("ü������"), Status(20, 0, 0, 0, 0), 100);
	m_listItems[6] = Item(Item::E_ITEM_KIND::POTION, _T("��������"), _T("HPȸ��"), Status(100, 0, 0, 0, 0), 100);
	m_listItems[7] = Item(Item::E_ITEM_KIND::POTION, _T("��������"), _T("MPȸ��"), Status(0,100, 0, 0, 0), 100);
	m_listItems[8] = Item(Item::E_ITEM_KIND::THROW, _T("¯��"), _T("�����������"), Status(0, 0, 50, 0, 0), 100);
	m_listItems[9] = Item(Item::E_ITEM_KIND::THROW, _T("���"), _T("�ټ��������"), Status(0, 0, 50, 0, 0), 100);
	//SaveFile();
	//LoadFile();
}

Item* ItemManager::GetItem(int idx)
{
	return &m_listItems[idx];
}