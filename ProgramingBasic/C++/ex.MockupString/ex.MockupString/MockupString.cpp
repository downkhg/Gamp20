#include <iostream>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더

using namespace std;
//문자열 클래스를 활용해보고, 해당 함수를 가능한 선까지 구현하고 테스트를 하여
//정상적으로 작동하는지, 확인해보자.
void STDStringMain()
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //생성자
	string strMsg2("DataTest"); //생성자
	string strCopyMsg = strMsg; //복사생성자
	string strCopyMsg2;
	strCopyMsg2 = strMsg2;
	//strCopyMsg2.append("Add");
	//strCopyMsg += "Add";

	cout << strMsg.c_str() << endl; //const char*를 리턴하는 함수 //Test
	printf("%d:%s\n", (int)strMsg.c_str(), strMsg.c_str()); //0x01:Test
	cout << strMsg2.c_str() << endl; //DataTest
	printf("%d:%s\n", (int)strMsg2.c_str(), strMsg2.c_str()); //0x02:DataTest
	printf("%d:%s\n", (int)strCopyMsg.c_str(), strCopyMsg.c_str()); //0x03:Test
	printf("%d:%s\n", (int)strCopyMsg2.c_str(), strCopyMsg2.c_str()); //0x04:Test
	cout << "##### STDStringMain End######" << endl;
}
//1char 2.float 3.int
void STDStringHangManGameMain()
{
	string strAnswer = "GAME";
	string strEmpty = "____";
	char cInput;
	while (true)
	{
		printf("Q:%s\n", strEmpty.c_str());
		scanf_s("%c", &cInput);

		int nResultIdx = strAnswer.find(cInput);//찾은 문자열의 주소값을 반환한다.
		if (nResultIdx != -1)
		{
			//찾은 문자열의주소에서 문자열시작주소를 빼서 현재 인덱스값을 계산한다.
			string temp = strEmpty.replace(nResultIdx, 1, 1, cInput);
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
	for (int i = 0; i < strAnswer.size(); i++)
		cout << i << ":" << strAnswer[i] << endl;
	string strSum;
	strSum = strAnswer + strEmpty;
	strSum = strAnswer;
}

namespace Mockup
{
	class string
	{
		char* pStr; //동적할당된 문자열의 주소를 저장할 포인터
	public:
		string()
		{
			pStr = NULL;
		}
		//생성자에서 동적할당된 메모리는 객체가 소멸될때 호출되어야한다.
		string(const char* str)
		{
			int nSize = strlen(str) + 1;
			//매개변수로 받은 문자열을 동적할당(문자열의 길이 +1 만큼)된 문자열에 포인터에 저장하고,
			pStr = new char[strlen(str) + 1];
			//동적할당된메모리에 매개변수의 문자열을 복사한다.
			strcpy_s(pStr, nSize, str);
			cout << "FakeString[" << this << "]:" << (int)pStr << endl;
		}
		string(const string& str)
		{
			int nSize = strlen(str.pStr) + 1;
			pStr = new char[nSize];
			strcpy_s(pStr, nSize, str.pStr);
			//pStr = str.pStr;
			cout << "FakeString Copy[" << this << "]:" << (int)pStr << endl;
		}
		//생성자에서 동적할당하였으므로 반드시 소멸자에서 동적할당된 객체를 정리한다.
		~string()
		{
			cout << "~FakeString[" << this << "]:" << (int)pStr << endl;
			delete[] pStr;
		}
		const char* c_str()
		{
			return pStr;
		}
		//함수나 연산자를 정의할때 고려해야하는것중 아닌것은?
		// 1.함수 2.리턴값 3.매개변수
		//함수를 정의할때 리턴값과 매개변수를 고려해서 선택하면된다.
		int find(const char)
		{
			return 0;
		}
		string& replace(int offset, int number, int count, const char replace)
		{
			string strTemp;
			return strTemp;
		}
		bool operator==(const string& str)
		{
			return false;
		}
		
		string operator+(const string& str)
		{
			string strTemp;
			return strTemp;
		}
		string operator=(const string& str)
		{
			pStr = str.pStr;
			return *this;
		}
		int size()
		{
			return 0;
		}
		char operator[](int idx)
		{
			return 0;
		}
		//friend: 다른객체가 자신의 객체의 private함수를 접근하게만드는 키워드. 통상적으로 사용할일은없음.
		//다만 연산자오버로딩할때 매개변수가 2개면 반드시 friend함수를 사용해야한다.
		friend ostream& operator<<(ostream& os, string str)
		{
			return os << str.c_str() << endl;
		}
	};
}

//1.char 2.string 3.bool
void MockupStringMain()
{
	cout << "##### FakeStringMain Start ######" << endl;
	Mockup::string strMsg("Test"); //생성자
	Mockup::string strMsg2("DataTest"); //생성자
	Mockup::string strCopyMsg = strMsg; //복사생성자
	Mockup::string strCopyMsg2;
	strCopyMsg2 = strMsg2;

	cout << strMsg.c_str() << endl; //const char*를 리턴하는 함수 //Test
	printf("%d:%s\n", (int)strMsg.c_str(), strMsg.c_str()); //0x01:Test
	cout << strMsg2.c_str() << endl; //DataTest
	printf("%d:%s\n", (int)strMsg2.c_str(), strMsg2.c_str()); //0x02:DataTest
	printf("%d:%s\n", (int)strCopyMsg.c_str(), strCopyMsg.c_str()); //0x03:Test
	cout << strCopyMsg << endl;
	printf("%d:%s\n", (int)strCopyMsg2.c_str(), strCopyMsg2.c_str()); //0x02:Test
	cout << "##### FakeStringMain End######" << endl;
}
//[] 매개변수
//1.char 2.bool 3.int
void HangManGameMain()
{
	Mockup::string strAnswer = "GAME";
	Mockup::string strEmpty = "____";
	char cInput;
	while (true)
	{
		printf("Q:%s\n", strEmpty.c_str());
		scanf_s("%c", &cInput);

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
	for (int i = 0; i < strAnswer.size(); i++)
		cout << i << ":" << strAnswer[i] << endl;
	Mockup::string strSum = strAnswer + strEmpty;
	
}


void main()
{
	//_CrtSetBreakAlloc(150); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 

	STDStringMain();
	MockupStringMain();
}