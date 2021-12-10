using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemObject : MonoBehaviour
{
    [SerializeField]
    Item m_cItem;
    Rigidbody m_cRigidbody;

    private void Awake()
    {
        m_cRigidbody = GetComponent<Rigidbody>();
    }


    private void OnEnable()
    {
        Debug.Log(gameObject.name+".OnEnable:" + m_cItem.Name);
        m_cRigidbody.velocity = Vector3.zero;
        m_cRigidbody.isKinematic = false;
    }

    private void OnDisable()
    {
        Debug.Log(gameObject.name + ".OnDisable:" + m_cItem.Name);
        m_cRigidbody.velocity = Vector3.zero;
        m_cRigidbody.isKinematic = true;
    }

    public void SetItem(ItemManager.E_ITEM item)
    {

    }
    public void SetItem(Item item)
    {
        //gameObject.SetActive(true);
        m_cItem = item;
    }

    public Item GetItem()
    {
        return m_cItem;
    }

    public void EatItem(ItemIventory itemIventory)
    {
        Debug.Log("GetItem:" + m_cItem.Name);
        itemIventory.SetItem(m_cItem);
        gameObject.SetActive(false);
       
    }

   

    //void Update() //굳이 사용하지않는 콜백함수는 호출하지않는 것이 좋다.
    //{
    //    ////싱글톤을 이용하면 다른객체에서도 테스트가 진행가능하다.
    //    ////이때 업데이트를 이용하지않으면 정확한시점이 아니라오류가 발생할수있다.
    //    //m_cItem = GameManager.GetInstance().ItemManager.GetItem(1);
    //}

    ////다음과 같이 인벤토리아이템획득을 처리할수도있다.
    //private void OnCollisionEnter(Collision collision)
    //{
    //    Debug.Log(this.gameObject.name + ".OnCollisionEnter(" + collision.gameObject.name + ")");
    //    Controller playerController = collision.gameObject.GetComponent<Controller>();

    //    if(playerController)
    //    {
    //        EatItem(playerController.GetPlayer().GetInventory());
    //    }
    //}

    private void OnTriggerEnter(Collider other)
    {

    }
}
