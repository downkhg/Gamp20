using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemButton : MonoBehaviour
{
    [SerializeField]
    Text m_textItemName;

    public void Initialize(Item item)
    {
        m_textItemName.text = item.Name;
    }

    //// Update is called once per frame
    //void Update()
    //{
    //    Item item = GameManager.GetInstance().ItemManager.GetItem(0);
    //    Initialize(item);
    //}
}
