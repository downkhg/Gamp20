using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    [SerializeField]
    Player m_cMaster;
    [SerializeField]
    float m_fSpeed = 1;
    [SerializeField]
    bool m_bMove = false;

    IEnumerator ProcessTimmer(float fTime)
    {
        m_bMove = true;
        yield return new WaitForSeconds(fTime);
        m_bMove = false;
        Destroy(this.gameObject);
    }

    public void Initialize(Player master, float speed, float time)
    {
        m_cMaster = master;
        m_fSpeed = speed;
        StartCoroutine(ProcessTimmer(time));
        //Destroy(this.gameObject, time);
    }

    // Update is called once per frame
    void Update()
    {
        if (m_bMove)
        {
            transform.Translate(Vector3.forward * m_fSpeed * Time.deltaTime);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag != m_cMaster.gameObject.tag)
        {
            Player target = other.GetComponent<Player>();
            m_cMaster.Attack(target);
        }
    }
}
