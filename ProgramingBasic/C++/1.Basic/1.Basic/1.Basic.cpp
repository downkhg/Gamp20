#include <iostream>//stdio대신사용

using namespace std;//표준함수가 정의되어있는 공간

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
////함수의 오버로딩: 같은이름으로 여러함수를 정의하는 것.
//int Sum(int a, int b, int c){ return a + b + c; }
//int Sum(int a, int b){ return a + b; }
//디폴트매개변수: 매개변수의 값을 지정하지않으면, 자동으로 들어가는 값.
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