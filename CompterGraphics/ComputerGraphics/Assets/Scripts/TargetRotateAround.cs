using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TargetRotateAround : MonoBehaviour
{
    public GameObject objTarget;
    public float fDist;
    public Vector3 vAsix = Vector3.up;
    public float fAngle = 1;

    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 vTargetPos = objTarget.transform.position;
        Vector3 vPos = this.transform.position;
        Vector3 vDist = vPos - vTargetPos;
        float fDist = vDist.magnitude;

        Quaternion qRot = Quaternion.Euler(vAsix * fAngle);

        Vector3 vRotDist = qRot * vDist;
        Vector3 vResultPos = vTargetPos + vRotDist;

        transform.position = vResultPos;

        Debug.DrawLine(vTargetPos, vResultPos, Color.green);
        transform.LookAt(objTarget.transform);
    }
}
