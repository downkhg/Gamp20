#include <iostream>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���

using namespace std;
//���ڿ� Ŭ������ Ȱ���غ���, �ش� �Լ��� ������ ������ �����ϰ� �׽�Ʈ�� �Ͽ�
//���������� �۵��ϴ���, Ȯ���غ���.
void STDStringMain()
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //������
	string strMsg2("DataTest"); //������
	string strCopyMsg = strMsg; //���������
	string strCopyMsg2;
	strCopyMsg2 = strMsg2;
	//strCopyMsg2.append("Add");
	//strCopyMsg += "Add";

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ� //Test
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

		int nResultIdx = strAnswer.find(cInput);//ã�� ���ڿ��� �ּҰ��� ��ȯ�Ѵ�.
		if (nResultIdx != -1)
		{
			//ã�� ���ڿ����ּҿ��� ���ڿ������ּҸ� ���� ���� �ε������� ����Ѵ�.
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
		char* pStr; //�����Ҵ�� ���ڿ��� �ּҸ� ������ ������
	public:
		string()
		{
			pStr = NULL;
		}
		//�����ڿ��� �����Ҵ�� �޸𸮴� ��ü�� �Ҹ�ɶ� ȣ��Ǿ���Ѵ�.
		string(const char* str)
		{
			int nSize = strlen(str) + 1;
			//�Ű������� ���� ���ڿ��� �����Ҵ�(���ڿ��� ���� +1 ��ŭ)�� ���ڿ��� �����Ϳ� �����ϰ�,
			pStr = new char[strlen(str) + 1];
			//�����Ҵ�ȸ޸𸮿� �Ű������� ���ڿ��� �����Ѵ�.
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
		//�����ڿ��� �����Ҵ��Ͽ����Ƿ� �ݵ�� �Ҹ��ڿ��� �����Ҵ�� ��ü�� �����Ѵ�.
		~string()
		{
			cout << "~FakeString[" << this << "]:" << (int)pStr << endl;
			delete[] pStr;
		}
		const char* c_str()
		{
			return pStr;
		}
		//�Լ��� �����ڸ� �����Ҷ� ����ؾ��ϴ°��� �ƴѰ���?
		// 1.�Լ� 2.���ϰ� 3.�Ű�����
		//�Լ��� �����Ҷ� ���ϰ��� �Ű������� ����ؼ� �����ϸ�ȴ�.
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
		//friend: �ٸ���ü�� �ڽ��� ��ü�� private�Լ��� �����ϰԸ���� Ű����. ��������� �������������.
		//�ٸ� �����ڿ����ε��Ҷ� �Ű������� 2���� �ݵ�� friend�Լ��� ����ؾ��Ѵ�.
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
	Mockup::string strMsg("Test"); //������
	Mockup::string strMsg2("DataTest"); //������
	Mockup::string strCopyMsg = strMsg; //���������
	Mockup::string strCopyMsg2;
	strCopyMsg2 = strMsg2;

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ� //Test
	printf("%d:%s\n", (int)strMsg.c_str(), strMsg.c_str()); //0x01:Test
	cout << strMsg2.c_str() << endl; //DataTest
	printf("%d:%s\n", (int)strMsg2.c_str(), strMsg2.c_str()); //0x02:DataTest
	printf("%d:%s\n", (int)strCopyMsg.c_str(), strCopyMsg.c_str()); //0x03:Test
	cout << strCopyMsg << endl;
	printf("%d:%s\n", (int)strCopyMsg2.c_str(), strCopyMsg2.c_str()); //0x02:Test
	cout << "##### FakeStringMain End######" << endl;
}
//[] �Ű�����
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

		int nResultIdx = strAnswer.find(cInput);//ã�� ���ڿ��� �ּҰ��� ��ȯ�Ѵ�.
		if (nResultIdx != -1)
		{
			//ã�� ���ڿ����ּҿ��� ���ڿ������ּҸ� ���� ���� �ε������� ����Ѵ�.
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
	//_CrtSetBreakAlloc(150); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	STDStringMain();
	MockupStringMain();
}