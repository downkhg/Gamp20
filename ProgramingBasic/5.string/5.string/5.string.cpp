#include <stdio.h>
//문자열: 문자배열
void StringTestMain()
{
	const int  SIZE = 3;
	char strInput[SIZE];
	
	strInput[0] = 'a';
	strInput[1] = 'b';
	strInput[2] = 'c';
	//strInput[3] = '\0';//널문자: 문자열의 끝을알리는 값.

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

void main()
{
	//StringTestMain();
	InputIDMain();
}