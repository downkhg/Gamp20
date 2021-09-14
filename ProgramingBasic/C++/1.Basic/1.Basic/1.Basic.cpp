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
//�ܾ���߱����(c���)
//1.���ڿ� Ŭ������ �̿��Ͽ� �����(�迭ó�� ���O)
//2.���ڿ��� �迭ó�� ��������ʰ�, ���ڿ����� �Լ��� �̿��Ͽ� �����
void HangManGameMain()
{
	string strAnswer = "GAME";
	string strEmpty = "____";
	char cInput;
	while (true)
	{
		printf("Q:%s\n", strEmpty.c_str());
		scanf("%c", &cInput);

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