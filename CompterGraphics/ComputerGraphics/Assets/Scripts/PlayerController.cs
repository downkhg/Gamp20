using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : Controller
{
    [SerializeField]
    Transform m_transGrab;
    [SerializeField]
    float m_fCurTime = -1;

    public bool ProcessTimemer(float maxtime)
    {
        if(m_fCurTime >= 0)
        {
            if (m_fCurTime <= maxtime)
            {
                m_fCurTime += Time.deltaTime;
                return true;
            }
        }
        m_fCurTime = -1;
        return false;
    }

    public Transform GrabPoint
    {
        get { return m_transGrab; }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.UpArrow))
            MoveProcess(Vector3.forward, m_cPlayer.MoveSpeed);

        if (Input.GetKey(KeyCode.DownArrow))
            MoveProcess(Vector3.back, m_cPlayer.MoveSpeed);

        if (Input.GetKey(KeyCode.RightArrow))
           RotateProcess(Vector3.up, m_cPlayer.AngleSpeed);

        if (Input.GetKey(KeyCode.LeftArrow))
            RotateProcess(Vector3.down,m_cPlayer.AngleSpeed);

        bool isCoolTime = ProcessTimemer(m_cPlayer.GetGun().ShotCoolTime);

        if (isCoolTime == false)
        {
            if (Input.GetKeyDown(KeyCode.Space))
            {
                //if(m_cPlayer.GetGun().Get)
                m_cPlayer.Shot();
                m_fCurTime = 0;
            }
        }
    }
}
