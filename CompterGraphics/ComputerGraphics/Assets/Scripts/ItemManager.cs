using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public struct Status
{
	public int nHP;
	public int nMP;
	public int nStr;
	public int nInt;
	public int nDef;

	public Status(int _hp = 0,int _mp = 0,int _str = 0,int _int = 0,int _def = 0)
	{
		nHP = _hp;
		nMP = _mp;
		nStr = _str;
		nInt = _int;
		nDef = _def;
	}
	public static Status operator+(Status status, int value)
	{
		status.nHP += value;
		status.nMP += value;
		status.nStr += value;
		status.nDef += value;
		status.nInt += value;
		return status;
	}
	public static Status operator +(Status status, Status statusAdd)
	{
		Status sResult = new Status();
		sResult.nHP = status.nHP + statusAdd.nHP;
		sResult.nMP = status.nMP + statusAdd.nMP;
		sResult.nStr = status.nStr + statusAdd.nStr;
		sResult.nDef = status.nDef + statusAdd.nDef;
		sResult.nInt = status.nInt + statusAdd.nInt;
		return sResult;
	}
	public static Status operator-(Status status, Status op)
	{
		Status sResult;
		sResult.nHP = status.nHP - op.nHP;
		sResult.nMP = status.nMP - op.nMP;
		sResult.nStr = status.nStr - op.nStr;
		sResult.nDef = status.nDef - op.nDef;
		sResult.nInt = status.nInt - op.nInt;
		return sResult;
	}
	public override string ToString()
    {
		return string.Format("HP:{0}\nMP:{1}\nStr:{2}\nDef:{1}\nStr:{2}\nDef:{3}\nInt:{0}\n",nHP, nMP, nStr, nDef, nInt);
    }
}

[System.Serializable]
public class Item
{
	[SerializeField]
	string m_strName;
	[SerializeField]
	string m_strInfo;
	[SerializeField]
	Status m_sStatus;
	[SerializeField]
	Sprite m_spriteIcon;
	public Status ItemStatus { set { m_sStatus = value; } get { return m_sStatus; } }
	public string Name { get { return m_strName; }  }
	public string Info { get { return m_strInfo; } }
	public Sprite Icon { get { return m_spriteIcon; } }

	public Item (string name, Status status, string info, string icon)
    {
		m_sStatus = status;
		m_strName = name;
		m_strInfo = info;
		m_spriteIcon = Resources.Load<Sprite>("Sprite/"+icon);
    }
}

public class ItemManager : MonoBehaviour
{
	public enum E_ITEM { HP_POTION, MP_POTION, MAX }
	[SerializeField]
	List<Item> m_listItem = new List<Item>((int)E_ITEM.MAX);

	public List<Item> ListItems { get{ return m_listItem; } }

	public Item GetItem(int idx)
    {
		return	m_listItem[idx];
    }

    // Start is called before the first frame update
    public void InitItems()
    {
		Debug.Log("ItemManager::Init() 1");
		m_listItem.Add(new Item("HP_Potion", new Status(100), "Recorvery HP", "HealingPotion"));
		m_listItem.Add(new Item("MP_Potion", new Status(0,100), "Recorvery MP", "ManaPotion"));
		Debug.Log("ItemManager::Awalk() 2");
	}
}
