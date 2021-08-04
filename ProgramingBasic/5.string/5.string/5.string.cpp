#include <stdio.h>
//문자열: 문자배열
void StringTestMain()
{
	const int  SIZE = 4;
	char strInput[SIZE] = "abc";//문자열초기화시 문자열의 끝에는 반드시 널문자가 삽입된다.
	
	/*strInput[0] = 'a';
	strInput[1] = 'b';
	strInput[2] = 'c';*/
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
//널문자 필요한이유? 메모리의 크기는 여유롭게 줄수있지만 실제 문자열의 길이는 그보다 작을수도있으므로, 불필요한 출력을 하지않기위해서.
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