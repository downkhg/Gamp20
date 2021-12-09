using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    [SerializeField]
    float m_fSpeed = 1;
    [SerializeField]
    bool m_bStop = false;

    IEnumerator ProcessTimmer(float fTime)
    {
        m_bStop = false;
        yield return new WaitForSeconds(fTime);
        m_bStop = true;
        Destroy(this.gameObject);
    }

    public void Initialize(float speed, float time)
    {
        m_fSpeed = speed;
        StartCoroutine(ProcessTimmer(time));
        //Destroy(this.gameObject, time);
    }

    // Update is called once per frame
    void Update()
    {
        if (!m_bStop)
        {
            transform.position += Vector3.forward * m_fSpeed * Time.deltaTime;
        }
    }
}
