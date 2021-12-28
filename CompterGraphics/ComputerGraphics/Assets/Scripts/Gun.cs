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

    [SerializeField]
    float m_fShotDist = 3;
    [SerializeField]
    float m_fShotCoolTime = 0.5f;

    public float ShotDist { get { return m_fShotDist; } }
    public float ShotCoolTime { get { return m_fShotCoolTime; } }

    public void SetShotDist()
    {
        m_fDestroyTime = m_fShotDist / m_fShotSpeed;
    }

    public void Shot(Player master, GameObject target)
    {
        SetShotDist();
        GameObject objBullet = Instantiate(m_prefabBullet, m_transMozzle.position, Quaternion.identity);
        if (target) objBullet.transform.LookAt(target.transform);
        else objBullet.transform.LookAt(m_transMozzle.position + transform.forward);
        Bullet bullet = objBullet.GetComponent<Bullet>();
        bullet.Initialize(master, m_fShotSpeed, m_fDestroyTime);
    }
}
