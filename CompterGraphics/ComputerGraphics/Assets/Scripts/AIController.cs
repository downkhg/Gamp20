using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AIController : Controller
{
    public enum E_AI_STATE { FIND, TRACKING, ATTACK, RETRUN  }
    [SerializeField]
    E_AI_STATE m_curAIState;

    public void SetAIState(E_AI_STATE state)
    {
        switch (state)
        {
            case E_AI_STATE.FIND:

                break;
            case E_AI_STATE.TRACKING:
                transform.LookAt(m_objTarget.transform);
                break;
            case E_AI_STATE.ATTACK:

                break;
            case E_AI_STATE.RETRUN:

                break;
        }
        m_curAIState = state;
    }

    public void UpdateAIState()
    {
        switch (m_curAIState)
        {
            case E_AI_STATE.FIND:
                if (FindTargetProcess())
                    SetAIState(E_AI_STATE.TRACKING);
                break;
            case E_AI_STATE.TRACKING:
                if(m_objTarget)
                {
                    MoveProcess(Vector3.forward, dynamic.MoveSpeed);
                }
                break;
            case E_AI_STATE.ATTACK:

                break;
            case E_AI_STATE.RETRUN:

                break;
        }
    }

    [SerializeField]
    float m_fSite;

    [SerializeField]
    GameObject m_objTarget;

    public bool FindTargetProcess()
    {
        Collider[] colliders = Physics.OverlapSphere(transform.position, m_fSite);

        if (colliders.Length > 0)
        {
            foreach (Collider collider in colliders)
            {
                if (collider.tag == "Player")
                {
                    m_objTarget = collider.gameObject;
                    return true;
                }
            }
        }
        return false;
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
       
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(transform.position, m_fSite);
    }
}