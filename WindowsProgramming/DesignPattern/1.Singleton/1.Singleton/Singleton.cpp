#include <iostream>
using namespace std;
class SingleObject
{
	static SingleObject* m_pInstance; //정적멤버변수: 모든클래스가 공유하는 변수
	SingleObject() { cout << "SingleObject:" << this << endl; }
	int m_nData;
public:
	~SingleObject() { cout << "~SingleObject:" << this << endl; }
	static SingleObject* GetInstance()
	{
		cout << "GetInstance Start:" << endl;
		if(m_pInstance == NULL)
			m_pInstance = new SingleObject();
		cout << "GetInstance End:" << endl;
		return m_pInstance;
	}
	int GetData()
	{
		return m_nData;
	}
	void ShowMessage()
	{
		cout << this << " SingleObject ShowMSG["<<&m_nData<<"]:"<< m_nData << endl;
	}
	void Release()
	{
		delete m_pInstance;
	}
};
//정적멤버변수는 전역변수처럼 선언해야만 사용가능하다.
//객체가 생성되지않으면, 메모리도 만들어질수없으므로, 
SingleObject* SingleObject::m_pInstance;

//다른클래스에서 싱글톤클래스는 제약(포함이나 사용관계)가 아니더라도 언제든 접근가능하다.
class CMain
{
	static void main()
	{
		cout << (int)SingleObject::GetInstance() << endl;
	}
};

void TestFunctionMain()
{
	cout << (int)SingleObject::GetInstance() << endl;
}

//싱글톤: 클래스의 인스턴스가 1개이상 존재 할수없는 클래스를 만드는 기법.(생성자 은닉,정적멤버)
int main()
{
	TestFunctionMain();
	//객체가 외부에서 생성가능하다면 몇개든지 만들수있으므로 싱글톤이 아니다.
	/*SingleObject cSingleObject;
	cout << (int)&cSingleObject << endl;*/
	SingleObject* pSingleObjectA = NULL;
	SingleObject* pArrSingleObjects[2] = {};
	
	pSingleObjectA = SingleObject::GetInstance();
	pSingleObjectA->ShowMessage();
	for (int i = 0; i < 2; i++)
		pArrSingleObjects[i] = SingleObject::GetInstance();

	cout << "pSingleObjectA:" << pSingleObjectA << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "pSingleObject[" << i << "]:" << pArrSingleObjects[i] << endl;
		pArrSingleObjects[i]->ShowMessage();
	}
	//인스턴스가 1개이므로 굳이 여러번 불러줄필요는 없다.
	pSingleObjectA->Release();
}