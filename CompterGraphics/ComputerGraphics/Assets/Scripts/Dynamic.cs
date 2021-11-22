using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    [SerializeField]
    float Speed;
    [SerializeField]
    float AngleSpeed;
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

    public void MoveProcess(Vector3 dir)
    {
        transform.Translate(dir * Speed * Time.deltaTime);
    }

    public void RotateProcess(Vector3 axis)
    {
        transform.Rotate(axis * AngleSpeed);
    }
}
