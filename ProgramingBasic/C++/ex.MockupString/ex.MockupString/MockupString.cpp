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
	string srtCopyMsg = strMsg; //���������

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ� //Test
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str()); //0x01:Test
	cout << strMsg2.c_str() << endl; //DataTest
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str()); //0x02:DataTest
	printf("%d:%s\n", srtCopyMsg.c_str(), srtCopyMsg.c_str()); //0x03:Test
	cout << "##### STDStringMain End######" << endl;
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
		string(string& str)
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
	};
}

void MockupStringMain()
{
	cout << "##### FakeStringMain Start ######" << endl;
	Mockup::string strMsg("Test"); //������
	Mockup::string strMsg2("DataTest"); //������
	Mockup::string srtCopyMsg = strMsg; //���������

	cout << strMsg.c_str() << endl; //const char*�� �����ϴ� �Լ� //Test
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str()); //0x01: Test
	cout << strMsg2.c_str() << endl; //DataTest
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str()); //0x02: DataTest
	cout << srtCopyMsg.c_str() << endl; //0x01: Test
	printf("%d:%s\n", srtCopyMsg.c_str(), srtCopyMsg.c_str()); //0x01:Test -> 0x03:Test
	cout << "##### FakeStringMain End######" << endl;
}

void main()
{
	//_CrtSetBreakAlloc(150); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	STDStringMain();
	MockupStringMain();
}