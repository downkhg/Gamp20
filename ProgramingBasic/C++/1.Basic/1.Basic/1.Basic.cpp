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

void RefMain()
{
	int nData = 10;
	int& refData = nData; //초기화하지않으면 오류가 난다.(null불가)
	//변수를 참조한다.
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

void ChararrayTestMain()
{
	const int SIZE = 128;
	char strFirstName[SIZE];
	char strLastName[SIZE];
	char strFullName[SIZE] = "";

	strcpy_s(strFirstName,"hg");
	strcpy_s(strLastName,"k");

	strcat_s(strFullName, strFirstName);
	strcat_s(strFullName, strLastName);
	cout << strFullName << endl;
}
//단어맞추기게임(c언어)
//1.문자열 클래스를 이용하여 만들기(배열처럼 사용O)
//2.문자열을 배열처럼 사용하지않고, 문자열내부 함수만 이용하여 만들기
void HangManGameMain()
{
	string strAnswer = "GAME";
	string strEmpty = "____";
	char cInput;
	while (true)
	{
		printf("Q:%s\n", strEmpty.c_str());
		scanf("%c", &cInput);

		int nResultIdx = strAnswer.find(cInput);//찾은 문자열의 주소값을 반환한다.
		if (nResultIdx != -1)
		{
			//찾은 문자열의주소에서 문자열시작주소를 빼서 현재 인덱스값을 계산한다.
			strEmpty.replace(nResultIdx, 1, 1, cInput);
		}
		else
			printf("not found!\n");

		if (strAnswer == strEmpty)
		{
			printf("Q:%s\n", strEmpty.c_str());
			break;
		}
		else
			printf("strcmp:%d\n", nResultIdx);
	}
}

void main()
{
	//NamespaceTestMain();
	//std::cout << "Hello World!" << std::endl;
	//SumTestMain();
	//RefMain();
	//StringTestMain();
	//ChararrayTestMain();
	HangManGameMain();
}