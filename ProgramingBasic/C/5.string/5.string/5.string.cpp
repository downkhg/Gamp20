#include <stdio.h>
#include <string.h>
//���ڿ�: ���ڹ迭
void StringTestMain()
{
	const int  SIZE = 4;
	char strInput[SIZE] = "abc";//���ڿ��ʱ�ȭ�� ���ڿ��� ������ �ݵ�� �ι��ڰ� ���Եȴ�.
	
	/*strInput[0] = 'a';
	strInput[1] = 'b';
	strInput[2] = 'c';*/
	//strInput[3] = '\0';//�ι���: ���ڿ��� �����˸��� ��.

	for (int i = 0; i < SIZE; i++)
		printf("%c", strInput[i]);
	printf("\n");

	int nSize = 0;
	while (strInput[nSize] != '\0')
	{
		printf("%c",strInput[nSize]);
		nSize++;
	}
	printf("\n");
	printf("Size:%d\n",nSize);
	printf("%s",strInput);
}
//�ι��� �ʿ�������? �޸��� ũ��� �����Ӱ� �ټ������� ���� ���ڿ��� ���̴� �׺��� �������������Ƿ�, ���ʿ��� ����� �����ʱ����ؼ�.
void InputIDMain()
{
	const int SIZE = 24;
	char strID[SIZE];
	printf("InputID:");
	scanf("%s", strID);

	for (int i = 0; i < SIZE; i++)
		printf("%c", strID[i]);
	printf("\n");

	int nSize = 0;
	while (strID[nSize] != '\0')
	{
		printf("%c", strID[nSize]);
		nSize++;
	}
	printf("\n");
	printf("%s",strID);
}
//Q:____
//A:A
//Q:_A__
//A:G
//Q:GA__
//.........
//A:GAME
//������: ����(���ڿ�),�Է°�(����),���ڿ�(���ڿ�)
//�˰���: ���信 �Է°��� ������, ���ڿ��� ä���ִ´�.  ����� ���ڿ��� ������ �ߴ��Ѵ�.
//������? -> ã��: ��繮�ڿ����� �ش��ϴ� ���� �ִ��� Ȯ���ϱ�, 
//������? -> ���ڿ��� ������ ��� �迭�� ���� ���ƾ��Ѵ�.
void HangMainMain()
{
	char strAnswer[32] = "GAME";
	char strEmpty[32] = "____";
	char cInput;
	while (true)
	{
		printf("Q:%s\n", strEmpty);
		scanf("%c", &cInput);

		int nIdx = 0;
		int nResultIdx = -1;
		while (strAnswer[nIdx] != '\0')
		{
			if (strAnswer[nIdx] == cInput)
			{
				nResultIdx = nIdx;
				break;
			}
			nIdx++;
		}
		if (nResultIdx > -1)
		{
			strEmpty[nResultIdx] = cInput;
			printf("A:%s\n", strEmpty);
		}
		else
			printf("not found!\n");
		
		int nMathCount = 0;
		int nResultCount = 0;
		for (nIdx = 0; strAnswer[nIdx] != '\0'; nIdx++)
		{
			if (strAnswer[nIdx] == strEmpty[nIdx])
				nMathCount++;
			nResultCount++;
		}
		if (nMathCount == nResultCount)
			break;
	}
}
//(��:���ڿ�)�� (�̸�:���ڿ�)�� (���ļ�?) (��ü�̸�:���ڿ�)�� ����� ���α׷�.
void FullNameMain()
{
	char strLastName[128];// = "k";
	char strFistName[128];// = "hg";
	char strFullName[256] = ""; //�ʱ�ȭ���������� �Լ����� �����Ⱚ������ �������� ���� ����ǰų� ����ȴ�.

	//strLastName = "k"; //�迭�̸��� �����Ͱ� �ƴ�. �����Ҽ�����.
	strcpy(strLastName, "k");
	strcpy(strFistName, "hg");

	printf("FullName:%s\n", strFullName);
	strcat(strFullName, strFistName);
	printf("FullName:%s\n", strFullName);
	strcat(strFullName, strLastName);
	printf("FullName:%s\n",strFullName);

	sprintf(strFullName, "%s %s", strLastName, strFistName);

	int nResult = strcmp(strLastName, strFistName);
	if (nResult == 0)
		printf("%d: %s == %s",nResult,strLastName,strFistName);
	else
		printf("%d: %s != %s",nResult, strLastName, strFistName);
}
void HangMainLibraryMain()
{
	char strAnswer[32] = "GAME";
	char strEmpty[32] = "____";
	char cInput;
	while (true)
	{
		printf("Q:%s\n", strEmpty);
		scanf("%c", &cInput);

		int nResultIdx = -1;
		char* pResult = strchr(strAnswer, cInput);//ã�� ���ڿ��� �ּҰ��� ��ȯ�Ѵ�.
		if (pResult)
		{
			//ã�� ���ڿ����ּҿ��� ���ڿ������ּҸ� ���� ���� �ε������� ����Ѵ�.
			nResultIdx = pResult - strAnswer;
			printf("ResultIdx:%d\n",nResultIdx);
		}
		else
			printf("not found!\n");

		int nResult = strcmp(strAnswer, strEmpty);
		if (nResult == 0)
			break;
		else
			printf("strcmp:%d\n",nResult);
	}
}
void main()
{
	//StringTestMain();
	//InputIDMain();
	//HangMainMain();
	//FullNameMain();
	HangMainLibraryMain();
}