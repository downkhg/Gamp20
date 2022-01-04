using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIManager : MonoBehaviour
{
    public enum E_GUI_STATE { NONE = -1, TITLE, GAMEOVER, THEEND, PLAY }

    [SerializeField]
    List<GameObject> m_listGUIScenes;
    [SerializeField]
    E_GUI_STATE m_eGurGUIState;

    [SerializeField]
    GUIPlayerInfo m_guiPlayerInfo;

    GameManager m_cGameManagerInstance;

    public E_GUI_STATE CurrentStatus { get { return m_eGurGUIState;  } }

    public void ShowGUIScenes(int idx)
    {
        for (int i = 0; i < m_listGUIScenes.Count; i++)
        {
            if (i == idx)
                m_listGUIScenes[i].SetActive(true);
            else
                m_listGUIScenes[i].SetActive(false);
        }
    }

    public void SetGUIState(E_GUI_STATE state)
    {
        switch (state)
        {
            case E_GUI_STATE.TITLE:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.GAMEOVER:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.THEEND:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.PLAY:
                Time.timeScale = 1;
                break;
        }
        ShowGUIScenes((int)state);
        m_eGurGUIState = state;
    }

    public void UpdateGUIState()
    {
        switch (m_eGurGUIState)
        {
            case E_GUI_STATE.TITLE:

                break;
            case E_GUI_STATE.GAMEOVER:

                break;
            case E_GUI_STATE.THEEND:

                break;
            case E_GUI_STATE.PLAY:
                {
                    if (Input.GetKeyDown(KeyCode.I))
                    {
                        if (m_bPopup)
                            ClosePopupIventory();
                        else
                            ShowPopupIventory();
                    }

                    m_cGameManagerInstance.Event3DStatusInfoUpdate(m_guiPlayerInfo);
                }
                break;
        }
    }

    public void EventGUIState(int idx)
    {
        SetGUIState((E_GUI_STATE)idx);
    }

    [SerializeField]
    bool m_bPopup;
    [SerializeField]
    GameObject m_objPopupLayer;
    [SerializeField]
    GUIItemInventory m_guiItemInventory;

    public E_GUI_STATE EGurGUIState { get => m_eGurGUIState; set => m_eGurGUIState = value; }
    public E_GUI_STATE EGurGUIState1 { get => m_eGurGUIState; set => m_eGurGUIState = value; }

    public void ShowPopupIventory()
    {
        Time.timeScale = 0;
        m_objPopupLayer.SetActive(true);
        m_guiItemInventory.gameObject.SetActive(true);
        m_bPopup = true;
    }

    public void ClosePopupIventory()
    {
        Time.timeScale = 1;
        m_objPopupLayer.SetActive(false);
        m_guiItemInventory.gameObject.SetActive(false);
        m_bPopup = false;
    }

    public void Initialize(GameManager gameManager)
    {
        m_cGameManagerInstance = gameManager;
        SetGUIState(m_eGurGUIState);
    }

    public void SetGUIIventory(ItemIventory itemIventory)
    {
        m_guiItemInventory.SetIventory(itemIventory);
    }

    // Update is called once per frame
    void Update()
    {
        UpdateGUIState();
    }
}
