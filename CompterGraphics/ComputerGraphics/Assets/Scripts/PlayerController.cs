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
            dynamic.MoveProcess(Vector3.forward);

        if (Input.GetKey(KeyCode.DownArrow))
            dynamic.MoveProcess(Vector3.back);

        if (Input.GetKey(KeyCode.RightArrow))
            dynamic.MoveProcess(Vector3.up);

        if (Input.GetKey(KeyCode.LeftArrow))
            dynamic.MoveProcess(Vector3.down);
    }
}
