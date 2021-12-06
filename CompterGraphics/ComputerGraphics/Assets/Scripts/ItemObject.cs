using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemObject : MonoBehaviour
{
    [SerializeField]
    Item m_cItem;

    public void SetItem(ItemManager.E_ITEM item)
    {

    }
    public void SetItem(Item item)
    {
        m_cItem = item;
    }

    // Start is called before the first frame update
    void Start()
    {
        m_cItem = GameManager.GetInstance().ItemManager.GetItem(0);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
