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
//데이터: 정답(문자열),입력값(문자),빈문자열(문자열)
//알고리즘: 정답에 입력값이 있을때, 빈문자열에 채워넣는다.  정답과 빈문자열이 같으면 중단한다.
//있을때? -> 찾기: 모든문자열에서 해당하는 값이 있는지 확인하기, 같으면? -> 빈문자열과 정답이 모든 배열의 값이 같아야한다.
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

void main()
{
	//StringTestMain();
	//InputIDMain();
	HangMainMain();
}