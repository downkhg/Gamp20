using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    [SerializeField]
    GameObject m_prefabBullet;
    [SerializeField]
    Transform m_transMozzle;
    [SerializeField]
    float m_fShotSpeed = 1;
    [SerializeField]
    float m_fDestroyTime;

    public void SetShotDist(float fDist)
    {
        m_fDestroyTime = fDist / m_fShotSpeed;
    }

    public void Shot(GameObject target)
    {
        GameObject objBullet = Instantiate(m_prefabBullet, m_transMozzle.position, Quaternion.identity);
        objBullet.transform.LookAt(target.transform);
        Bullet bullet = objBullet.GetComponent<Bullet>();
        bullet.Initialize(m_fShotSpeed, m_fDestroyTime);
    }
}
