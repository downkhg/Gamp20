using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField]
    List<ItemObject> m_listItemObject;
    [SerializeField]
    ItemManager m_cItemManager;

    public List<ItemObject> ItemObjects
    {
        get { return m_listItemObject; }
    }
    public ItemManager ItemManager
    {
        get { return m_cItemManager; }
    }
    //싱글톤기법: 객체는 원래 1개만 생성되로록 규칙이 정해져있어야하지만,
    //인스펙터사용등 편리함을 이유로 유니티에서 느슨한 규칙을 적용한것임.
    static GameManager m_cInstance;

    static public GameManager GetInstance()
    {
        return m_cInstance;
    }

    private void Awake()
    {
        m_cInstance = this;
    }

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("GameManager::Start() 1");
        m_cItemManager.InitItems();
        for (int i = 0; i < m_listItemObject.Count; i++)
        {
            m_listItemObject[i].SetItem(m_cItemManager.GetItem(0));
        }
        Debug.Log("GameManager::Start() 1");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
