#include <stdio.h>
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
void HangMainMain()
{

}

void main()
{
	//StringTestMain();
	InputIDMain();
}