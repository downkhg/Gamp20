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

void main()
{
	//NamespaceTestMain();
	//std::cout << "Hello World!" << std::endl;
	SumTestMain();
}