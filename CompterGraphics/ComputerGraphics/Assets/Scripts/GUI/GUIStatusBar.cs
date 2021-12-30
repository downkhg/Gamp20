using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class GUIStatusBar : MonoBehaviour
{
    [SerializeField]
    Image m_imgStatusBar;
    [SerializeField]
    Text m_textStatusName;
    [SerializeField]
    RectTransform m_rectStatusBarBG;

    public void Initialize(string name,Color color)
    {
        m_textStatusName.text = name;
        m_imgStatusBar.color = color;
    }

    public void UpdateStatus(float cur, float max)
    {
        RectTransform rectTransform = m_imgStatusBar.gameObject.GetComponent<RectTransform>();
        Vector2 vSize = rectTransform.sizeDelta;
        float fRat = cur / max;
        vSize.x = m_rectStatusBarBG.sizeDelta.x * fRat;
        rectTransform.sizeDelta = vSize;
    }
}
