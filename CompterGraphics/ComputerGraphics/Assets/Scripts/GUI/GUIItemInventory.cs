using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemInventory : MonoBehaviour
{
    [SerializeField]
    List<GUIItemButton> m_listGuiItemButton;
    [SerializeField]
    GridLayoutGroup m_gridLayoutContent;

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
            GameObject objButton = Instantiate(prefabButton, m_gridLayoutContent.transform);
            GUIItemButton guiItemButton = objButton.GetComponent<GUIItemButton>();
            guiItemButton.Initialize(items[i]);
            m_listGuiItemButton.Add(guiItemButton);
        }
        ResizeContent();
    }

    public void ResizeContent()
    {
        RectTransform rectTransform = m_gridLayoutContent.gameObject.GetComponent<RectTransform>();
        int nCol = (int)(rectTransform.sizeDelta.x / m_gridLayoutContent.cellSize.x);
        int nRow = m_listGuiItemButton.Count / nCol;
        if (nCol % m_listGuiItemButton.Count > 0) nRow++;
        float fHeight = m_gridLayoutContent.cellSize.y * nRow;
        rectTransform.sizeDelta = new Vector2(rectTransform.sizeDelta.x, fHeight);
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
