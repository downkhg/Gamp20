using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AIController : Controller
{
    public enum E_AI_STATE { FIND, TRACKING, ATTACK, RETURN  }
    [SerializeField]
    E_AI_STATE m_curAIState;

    public void SetAIState(E_AI_STATE state)
    {
        switch (state)
        {
            case E_AI_STATE.FIND:

                break;
            case E_AI_STATE.TRACKING:
                transform.LookAt(m_objTarget.transform.parent);
                break;
            case E_AI_STATE.ATTACK:

                break;
            case E_AI_STATE.RETURN:

                break;
        }
        m_curAIState = state;
    }

    public void UpdateAIState()
    {
        switch (m_curAIState)
        {
            case E_AI_STATE.FIND:
                if (m_objTarget == null)
                    SetAIState(E_AI_STATE.RETURN);
                break;
            case E_AI_STATE.TRACKING:
                if(m_objTarget)
                {
                    TrackingProcess();
                }
                break;
            case E_AI_STATE.ATTACK:

                break;
            case E_AI_STATE.RETURN:

                break;
        }
    }

    [SerializeField]
    float m_fSite;

    [SerializeField]
    GameObject m_objTarget;

    public bool ArcColCheak(GameObject target, float angle, Vector3 forword)
    {
        Vector3 vTargetPos = target.transform.position;
        Vector3 vPos = this.transform.position;

        Vector3 vTargetToDir = vTargetPos - vPos;
        float fAngle = Vector3.Angle(forword, vTargetToDir);

        float fHalfAngle = angle * 0.5f;
     
        Quaternion qRotRight = Quaternion.Euler(Vector3.up * fHalfAngle);
        Vector3 vEndPosRight = qRotRight * forword * m_fSite;
        Debug.DrawLine(vPos, vPos + vEndPosRight, Color.red);
        Quaternion qRotLeft = Quaternion.Euler(Vector3.down * fHalfAngle);
        Vector3 vEndPosLeft = qRotLeft * forword * m_fSite;
        Debug.DrawLine(vPos, vPos + vEndPosLeft, Color.red);
        Debug.DrawLine(vPos, vPos + forword*m_fSite, Color.blue);

        if (fAngle < fHalfAngle)
            return true;

        return false;
    }

    public bool RayCastWall()
    {
        RaycastHit raycastHit;
        //int nLayer = 1 << LayerMask.NameToLayer("Wall");
        if (Physics.Raycast(transform.position, transform.forward, out raycastHit))
        {
            if (raycastHit.transform.tag == "Wall")
            {
                Debug.Log("RaycastHit:" + raycastHit.collider.gameObject.name);
                return true;
            }
        }

        return false;
    }

    public bool FindTargetProcess()
    {
        Collider[] colliders = Physics.OverlapSphere(transform.position, m_fSite);

        if (colliders.Length > 0)
        {
            foreach (Collider collider in colliders)
            {
                if (collider.tag == "Player" && collider.transform.parent != null)
                {
                    if (ArcColCheak(collider.transform.parent.gameObject, 120, transform.forward))
                    {
                        if (RayCastWall() == false)
                        {
                            m_objTarget = collider.gameObject.transform.gameObject;
                            return true;
                        }
                    }
                }
            }
        }
        m_objTarget = null;
        return false;
    }

    public void TrackingProcess()
    {
        if (Vector3.Distance(transform.position, m_objTarget.transform.parent.transform.position) > Time.deltaTime)
            MoveProcess(Vector3.forward, dynamic.MoveSpeed);
        //else
        //    SetAIState(E_AI_STATE.ATTACK);
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        UpdateAIState();
    }

    private void FixedUpdate()
    {
        if (FindTargetProcess())
            SetAIState(E_AI_STATE.TRACKING);
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(transform.position, m_fSite);
    }
}