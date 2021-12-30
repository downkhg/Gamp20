using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIPlayerInfo : MonoBehaviour
{
    [SerializeField]
    Text m_textName;
    [SerializeField]
    Text m_textLv;
    [SerializeField]
    GUIStatusBar m_guiHPBar;
    [SerializeField]
    GUIStatusBar m_guiMPBar;

    public void UpdataPlayerStatus(Controller controller)
    {
        Player player = controller.GetPlayer();
        m_textName.text = player.gameObject.name;
        m_textLv.text = string.Format("Lv.{0}", player.Lv);
        m_guiHPBar.UpdateStatus(player.PlayerStatus.nHP, 100);
        m_guiMPBar.UpdateStatus(player.PlayerStatus.nMP, 100);
    }

    // Start is called before the first frame update
    void Start()
    {
        m_guiHPBar.Initialize("HP", Color.red);
        m_guiMPBar.Initialize("MP", Color.blue);
    }
}
