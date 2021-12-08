using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AIController : Controller
{
    public enum E_AI_STATE { FIND, TRACKING, ATTACK, RETURN  }
    [SerializeField]
    E_AI_STATE m_curAIState;

    IEnumerator ProcessAttack()
    {
        do
        {
            yield return new WaitForSeconds(m_fShotCoolTime);
            m_cPlayer.Shot();
        } while (m_curAIState == E_AI_STATE.ATTACK);
    }

    public void SetAIState(E_AI_STATE state)
    {
        if (m_curAIState == state) return;
        //Debug.Log("SetAIState:"+state);
        switch (state)
        {
            case E_AI_STATE.FIND:
                m_objTarget = null;
                break;
            case E_AI_STATE.TRACKING:
                if(m_objTarget)
                    transform.LookAt(m_objTarget.transform.parent);
                break;
            case E_AI_STATE.ATTACK:
                StartCoroutine(ProcessAttack());
                break;
            case E_AI_STATE.RETURN:
                transform.LookAt(m_objResponPoint.transform);
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
                if (m_objTarget)
                {
                    if (!TrackingProcess(m_objTarget.transform.parent.gameObject))
                        SetAIState(E_AI_STATE.ATTACK);
                }
                else
                    SetAIState(E_AI_STATE.RETURN);
                break;
            case E_AI_STATE.ATTACK:
                if (m_objTarget == null)
                {
                    SetAIState(E_AI_STATE.RETURN);
                }
               
                break;
            case E_AI_STATE.RETURN:
                if (TrackingProcess(m_objResponPoint) == false)
                    SetAIState(E_AI_STATE.FIND);
                break;
        }
    }

    [SerializeField]
    float m_fSite;

    [SerializeField]
    float m_fShotDist = 3;
    [SerializeField]
    float m_fShotCoolTime = 0.5f;

    [SerializeField]
    GameObject m_objTarget;
    [SerializeField]
    GameObject m_objResponPoint;

    public bool ArcColCheak(GameObject target, float angle, Vector3 forward)
    {
        Vector3 vTargetPos = target.transform.position;
        Vector3 vPos = this.transform.position;

        Vector3 vTargetToDir = vTargetPos - vPos;
        float fAngle = Vector3.Angle(forward, vTargetToDir);

        float fHalfAngle = angle * 0.5f;
     
        Quaternion qRotRight = Quaternion.Euler(Vector3.up * fHalfAngle);
        Vector3 vEndPosRight = qRotRight * forward * m_fSite;
        Debug.DrawLine(vPos, vPos + vEndPosRight, Color.red);
        Quaternion qRotLeft = Quaternion.Euler(Vector3.down * fHalfAngle);
        Vector3 vEndPosLeft = qRotLeft * forward * m_fSite;
        Debug.DrawLine(vPos, vPos + vEndPosLeft, Color.red);
        Debug.DrawLine(vPos, vPos + forward*m_fSite, Color.blue);

        if (fAngle < fHalfAngle)
            return true;

        return false;
    }

    public bool RayCastWall(GameObject target)
    {
        Vector3 vTargetPos = target.transform.position;
        Vector3 vPos = this.transform.position;
        Vector3 vTargetToDist = vTargetPos - vPos;

        RaycastHit raycastHit;
       
        //int nLayer = 1 << LayerMask.NameToLayer("Wall");
        if (Physics.Raycast(transform.position, vTargetToDist.normalized, out raycastHit, m_fSite))
        {
            if (raycastHit.transform.tag == "Wall")
            {
                Debug.DrawLine(vPos, vTargetPos, Color.red);
                Debug.Log("RaycastHit:" + raycastHit.collider.gameObject.name);
                return true;
            }
            else
                Debug.DrawLine(vPos, vTargetPos, Color.green);
        }

        return false;
    }

    public bool FindTargetProcess()
    {
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Collider[] colliders = Physics.OverlapSphere(transform.position, m_fSite, nLayer);

        if (colliders.Length > 0)
        {
            foreach (Collider collider in colliders)
            {
                if (collider.transform.parent != null)
                {
                    if (ArcColCheak(collider.transform.parent.gameObject, 120, transform.forward))
                    {
                        if (RayCastWall(collider.transform.parent.gameObject) == false)
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

    public bool TrackingProcess(GameObject objTarget)
    {
        Vector3 vPos = transform.position;
        Vector3 vTargetPos = objTarget.transform.position;

        float fDist = (vTargetPos - vPos).magnitude;

        if (fDist > m_fShotDist)
        {
            if (Vector3.Distance(transform.position, objTarget.transform.position) > Time.deltaTime)
            {
                MoveProcess(Vector3.forward, m_cPlayer.MoveSpeed);
                return true;
            }      
        }

        return false;
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
        {
            if (m_curAIState != E_AI_STATE.ATTACK)
            {
                SetAIState(E_AI_STATE.TRACKING);
            }
            else
                transform.LookAt(m_objTarget.transform);
        }
     
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(transform.position, m_fSite);
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, m_fShotDist);
    }
}