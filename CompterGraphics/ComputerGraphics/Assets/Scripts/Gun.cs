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
    float m_fShotPower;

    public void Shot()
    {
        GameObject objBullet = Instantiate(m_prefabBullet, m_transMozzle.position, Quaternion.identity);
        Rigidbody rigidbody = objBullet.GetComponent<Rigidbody>();
        rigidbody.AddForce(transform.forward * m_fShotPower);
    }
}
