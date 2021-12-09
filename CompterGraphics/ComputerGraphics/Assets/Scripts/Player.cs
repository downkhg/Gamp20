using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    [SerializeField]
    ItemIventory m_cItemIventory;
    [SerializeField]
    Gun m_cGun;
    [SerializeField]
    float m_fSpeed;
    [SerializeField]
    float m_fAngleSpeed;

    public ItemIventory GetInventory()
    {
        return m_cItemIventory;
    }

    public Gun GetGun()
    {
        return m_cGun;
    }

    public float MoveSpeed
    {
        get { return m_fSpeed; }
    }
    public float AngleSpeed
    {
        get { return m_fAngleSpeed;  }
    }

    public void Shot()
    {
        AIController cAIController = transform.parent.GetComponent<AIController>();
        m_cGun.SetShotDist(cAIController.ShotDist);
        m_cGun.Shot(cAIController.GetTarget());
    }

    private void Awake()
    {
        m_cItemIventory = GetComponent<ItemIventory>();
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }
    //1,3인칭에서는 케릭터가 바라보는 방향으로 이동한다.(회전,이동)
    // Update is called once per frame
    void Update()
    {
        //if (Input.GetKey(KeyCode.UpArrow))
        //    MoveProcess(Vector3.forward);
        ////transform.Translate(Vector3.forward * Time.deltaTime);
        ////transform.position += Vector3.forward * Time.deltaTime;
        //if (Input.GetKey(KeyCode.DownArrow))
        //    MoveProcess(Vector3.back);
        ////transform.Translate(Vector3.back * Time.deltaTime);
        ////transform.position += Vector3.back * Time.deltaTime;

        //if (Input.GetKey(KeyCode.RightArrow))
        //    MoveProcess(Vector3.up);
        //    //transform.Rotate(Vector2.up);
        //if (Input.GetKey(KeyCode.LeftArrow))
        //    MoveProcess(Vector3.down);
        ////transform.Rotate(Vector2.down);
    }

    private void FixedUpdate()
    {
        BoxCollider boxCollider = GetComponent<BoxCollider>();
        Vector3 vPos = transform.position;
        Collider[] colliders = Physics.OverlapBox(vPos + boxCollider.center, boxCollider.size * 0.5f, transform.rotation);

        if (colliders.Length > 0)
        {
            foreach (Collider collider in colliders)
            {
                ItemObject itemObject = collider.gameObject.GetComponent<ItemObject>();

                if (itemObject != null)
                { 
                    itemObject.EatItem(m_cItemIventory);
                }
            }
        }
    }

    ////충돌체크 콜백함수는 리지드바디가 있는 대상에서만 사용가능하다. 그러므로 이런 경우 플레이어 측에서 충돌체크가 작동하지않을수있다.
    //private void OnCollisionEnter(Collision collision)
    //{
    //    Debug.Log(this.gameObject.name + ".OnCollisionEnter(" + collision.gameObject.name + ")");
    //    ItemObject itemObject = collision.gameObject.GetComponent<ItemObject>();

    //    if (itemObject == null)
    //        m_cItemIventory.SetItem(itemObject.GetItem());
    //}

    //private void OnTriggerEnter(Collider other)
    //{

    //}
}
