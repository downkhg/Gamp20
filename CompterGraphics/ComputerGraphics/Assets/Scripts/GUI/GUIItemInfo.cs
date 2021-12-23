using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemInfo : MonoBehaviour
{
    [SerializeField]
    Text m_textStatus;
    [SerializeField]
    Text m_textInfo;
    [SerializeField]
    Image m_imgIcon;

    public void Initialize(Item item)
    {
        m_textStatus.text = item.ItemStatus.ToStatusText();
        m_textInfo.text = item.Info;
        m_imgIcon.sprite = item.Icon; 
    }
    public Text Status { get { return m_textStatus; } }
    public Text Info { get { return m_textInfo; } }
    public Image Icon { get { return m_imgIcon; } }

    //// Update is called once per frame
    //void Update()
    //{
    //    Item item = GameManager.GetInstance().ItemManager.GetItem(0);
    //    Initialize(item);
    //}
}
