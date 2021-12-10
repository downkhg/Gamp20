using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    [SerializeField]
    GameObject m_objTarget;
    [SerializeField]
    float m_fTime;
    [SerializeField]
    bool m_bHide = false;

    IEnumerator ProcessTimmer(float time)
    {
        Hide();
        yield return new WaitForSeconds(time);
        Show();
    }

    public void Hide()
    {
        Debug.Log(gameObject.name + ".Hide()");
        m_bHide = true;
        m_objTarget.transform.position += Vector3.down * 1000;
        m_objTarget.SetActive(false);
        
    }

    public void Show()
    {
        Debug.Log(gameObject.name + ".Show()");
        m_objTarget.transform.position = this.transform.position;
        m_objTarget.SetActive(true);
        m_bHide = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (m_objTarget.activeSelf == false && m_bHide == false)
        {
            StartCoroutine(ProcessTimmer(m_fTime));
        }
    }
}
