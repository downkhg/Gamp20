#include <iostream>//stdio��Ż��

using namespace std;//ǥ���Լ��� ���ǵǾ��ִ� ����

namespace A
{
	int g_nData;

	void PrintData()
	{
		cout << "DataA:" << g_nData << endl;
	}
}

namespace B
{
	int g_nData;

	void PrintDataB()
	{
		cout << "DataB:" << g_nData << endl;
	}
}

using namespace A;
//using namespace B;

void NamespaceTestMain()
{
	g_nData = 10;
	PrintData();

	B::g_nData = 20;
	B::PrintDataB();
}
////�Լ��� �����ε�: �����̸����� �����Լ��� �����ϴ� ��.
//int Sum(int a, int b, int c){ return a + b + c; }
//int Sum(int a, int b){ return a + b; }
//����Ʈ�Ű�����: �Ű������� ���� ��������������, �ڵ����� ���� ��.
int Sum(int a, int b = 0, int c = 0) { return a + b + c; }

void SumTestMain()
{
	cout << "Sum1:" << Sum(10) << endl;
	cout << "Sum2:"<< Sum(10, 20) << endl;
	cout << "Sum3:" << Sum(10, 20, 30) << endl;
}

void RefMain()
{
	int nData = 10;
	int& refData = nData; //�ʱ�ȭ���������� ������ ����.(null�Ұ�)
	//������ �����Ѵ�.
	cout << "1.Data:" << nData << endl;
	cout << "1.refData:" << refData << endl;
	nData = 20;
	cout << "2.Data:" << nData << endl;
	cout << "2.refData:" << refData << endl;
	refData = 30;
	cout << "3.Data:" << nData << endl;
	cout << "3.refData:" << refData << endl;
}

void StringTestMain()
{
	string strFirstName;
	string strLastName;
	string strFullName;

	strFirstName = "hg";
	strLastName = "k";

	strFullName = strFirstName + strLastName;
	cout << strFullName << endl;
}

void main()
{
	//NamespaceTestMain();
	//std::cout << "Hello World!" << std::endl;
	//SumTestMain();
	//RefMain();
	StringTestMain();
}