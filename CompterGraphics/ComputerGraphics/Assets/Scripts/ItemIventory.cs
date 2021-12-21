using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemIventory : MonoBehaviour
{
    [SerializeField]
    List<Item> m_listItem = null;

    public List<Item> GetlistItem()
    {
        return m_listItem;
    }

    public Item GetItem(int idx)
    {
        return m_listItem[idx];
    }

    public void SetItem(Item item)
    {
        m_listItem.Add(item);
    }

    public void TestIventory(int count)
    {
        ItemManager itemManager = GameManager.GetInstance().ItemManager;

        for(int c = 0;  c < count; c++)
        {
            for (int i = 0; i < itemManager.ListItems.Count; i++)
            {
                SetItem(itemManager.GetItem(i));
            }
        }
    }

    public void Initialize(int size)
    {
        if (m_listItem == null)
        {
            m_listItem = new List<Item>(size);
        }
        else
            Debug.LogError("Item list is not null !!!!");
    }

    private void OnGUI()
    {
        int width = 100, height = 20;
        int x = 0, y = 0;
       
        for(int i = 0; i < m_listItem.Count; i++)
        {
            y = height * i;
            Rect rect = new Rect(x, y, width, height);
            GUI.Box(rect, m_listItem[i].Name);
        }
    }
}
