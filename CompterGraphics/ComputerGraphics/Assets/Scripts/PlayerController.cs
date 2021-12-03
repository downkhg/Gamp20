using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : Controller
{
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

        if (Input.GetKeyDown(KeyCode.Space))
        {
            m_cPlayer.Shot();
        }
    }
}
