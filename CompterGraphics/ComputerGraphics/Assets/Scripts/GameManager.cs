using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField]
    List<ItemObject> m_listItemObject;
    [SerializeField]
    ItemManager m_cItemManager;
    [SerializeField]
    Dictionary<string, PlayerController> m_dicPlayerController = new Dictionary<string, PlayerController>();
    [SerializeField]
    string m_strID;
    [SerializeField]
    List<PlayerController> m_listPlayerControllers;
    [SerializeField]
    int m_nPlayerIdx = 0;
    [SerializeField]
    Camera m_cMainCamera;

    public int PlayerIdx { get { return m_nPlayerIdx; } set { m_nPlayerIdx = value; } }
        
    public List<ItemObject> ItemObjects
    {
        get { return m_listItemObject; }
    }
    public ItemManager ItemManager
    {
        get { return m_cItemManager; }
    }
    public List<PlayerController> PlayerControllList
    {
        get { return m_listPlayerControllers; }
    }

    public int NPlayerIdx { get => m_nPlayerIdx; set => m_nPlayerIdx = value; }
    public GUIManager CGUIManager { get => m_cGUIManager; set => m_cGUIManager = value; }
    public string StrID { get => m_strID; set => m_strID = value; }
    public Dictionary<string, PlayerController> DicPlayerController { get => m_dicPlayerController; set => m_dicPlayerController = value; }

    public PlayerController GetCurrentPlayerControllers()
    {
        return m_listPlayerControllers[m_nPlayerIdx];
    }
    public PlayerController GetPlayeControllers(int idx)
    {
        return m_listPlayerControllers[idx];
    }

    [SerializeField]
    GUIManager m_cGUIManager;

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

    [SerializeField]
    Camera m_cCarmera;

    void UpdateInputProcess()
    {

        Ray ray = m_cCarmera.ScreenPointToRay(Input.mousePosition);
        RaycastHit raycastHit = new RaycastHit();
        float fRayDist = 100;
        int nLayer = 1 << LayerMask.NameToLayer("Object");

        if (Input.GetMouseButtonDown(0))
        {
            if (Physics.Raycast(ray.origin, ray.direction, out raycastHit, fRayDist, nLayer, QueryTriggerInteraction.Collide))
            {
                Collider collider = raycastHit.collider;
                //Debug.DrawRay(ray.origin, ray.direction, Color.green);
                Debug.DrawLine(ray.origin, ray.origin + ray.direction * fRayDist, Color.green);
                Debug.Log("Ray Ficking:" + collider.gameObject.name);
                PlayerController playerController = GetPlayeControllers(PlayerIdx);

                Transform transPickup = collider.transform;

                if(playerController.GrabPoint)
                {
                    transPickup.SetParent(playerController.GrabPoint);
                    transPickup.localPosition = Vector3.zero;
                }
            }
            else
                Debug.DrawLine(ray.origin, ray.origin + ray.direction * fRayDist, Color.red);
        }
    }

    public ItemIventory EventShowMeTheItems()
    {
        Controller controller = GetPlayeControllers(m_nPlayerIdx);
        Player player = controller.GetPlayer();
        ItemIventory itemIventory = player.GetComponent<ItemIventory>();
        itemIventory.TestIventory(10);
        return itemIventory;
    }

    public void Event3DStatusInfoUpdate(GUIPlayerInfo guiPlayerInfo)
    {
        PlayerController playerController = GetCurrentPlayerControllers();
        Vector3 v2DPos = m_cMainCamera.WorldToScreenPoint(playerController.transform.position);
        guiPlayerInfo.transform.position = v2DPos;
        guiPlayerInfo.UpdataPlayerStatus(playerController);
    }

    public void EventCreatePlayerController(string id)
    {
        GameObject prefabsPlayerContller = Resources.Load("Prefabs/PlayerController") as GameObject;
        GameObject objPlayerContller = Instantiate(prefabsPlayerContller);
        PlayerController playerController = objPlayerContller.GetComponent<PlayerController>();
        m_dicPlayerController.Add(id,playerController);
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
        m_cGUIManager.Initialize(this);
        ItemIventory itemIventory = EventShowMeTheItems();
        m_cGUIManager.SetGUIIventory(itemIventory);
        EventCreatePlayerController(m_strID);
        Debug.Log("GameManager::Start() 1");
    }

    private void Update()
    {
        
    }

    private void FixedUpdate()
    {
        UpdateInputProcess();
    }
}
