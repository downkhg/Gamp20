using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIItemInventory : MonoBehaviour
{
    [SerializeField]
    List<GUIItemButton> m_listGuiItemButton;


    public void Initialize(int size)
    {
        m_listGuiItemButton = new List<GUIItemButton>(size);
    }

    public void SetIventory(ItemIventory itemIventory)
    {
        List<Item> items = itemIventory.GetlistItem();
        GameObject prefabButton = Resources.Load("Prefabs/GUI/ItemButton") as GameObject;
        for(int i = 0; i  < items.Count; i++)
        {
            GameObject objButton = Instantiate(prefabButton);
            GUIItemButton guiItemButton = objButton.GetComponent<GUIItemButton>();
            m_listGuiItemButton.Add(guiItemButton);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
