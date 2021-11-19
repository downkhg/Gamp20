using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float Speed;
    // Start is called before the first frame update
    void Start()
    {
        
    }
    //1,3인칭에서는 케릭터가 바라보는 방향으로 이동한다.(회전,이동)
    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.UpArrow))
            transform.Translate(Vector3.forward * Time.deltaTime);
            //transform.position += Vector3.forward * Time.deltaTime;
        if (Input.GetKey(KeyCode.DownArrow))
            transform.Translate(Vector3.back * Time.deltaTime);
        //transform.position += Vector3.back * Time.deltaTime;

        if (Input.GetKey(KeyCode.RightArrow))
            transform.Rotate(Vector2.up);
        if (Input.GetKey(KeyCode.LeftArrow))
            transform.Rotate(Vector2.down);
    }
}
