#include <stdio.h>

void ArrayMain()
{
	const int nSize = 5;
	int arrScores[nSize] = {100,90,80,70,60};
	int nMemorySize = sizeof(arrScores);
	int nArraySize = nMemorySize / sizeof(arrScores[0]);
	printf("MemorySize/ArraySize:%d/%d\n",nMemorySize,nArraySize);

	/*arrScores[0] = 100;
	arrScores[1] = 90;
	arrScores[2] = 80;
	arrScores[3] = 70;
	arrScores[4] = 60;*/

	for (int i = 0; i < 5; i++)
		printf("[%d]%d,", i, arrScores[i]);
	printf("\n");

	int arrCopyScore[nSize];
	//arrCopyScore = arrScores;
	printf("Score/CopyScore:%d/%d\n",arrCopyScore,arrScores);
	for (int i = 0; i < nSize; i++)
		arrCopyScore[i] = arrScores[i];
}
//배열에서 최소값을 찾아서 출력하라.
//(최소값, 배열내에서 가장 작은 값을 찾는것)
//데이터: 30,40,50,10,20, 최소값을 검사하기위해 저장할 변수
//알고리즘: 
//모든배열의 값을 비교해서 가장 작은 값이 무엇인지 찾는다.
//첫번째값을 저장하고, 저장된값보다 다음 값이 작으면 값을 최소값으로 교채한다.
void ArrayFindMinDataMain()
{
	int arrData[5] = { 10,20,30,60,70 };
	int nMin = arrData[0];

	for(int i = 0; i<5; i++)
	{
		if (nMin < arrData[i])
		{
			nMin = arrData[i];
		}
	}
	printf("Min:%d\n",nMin);
}

void main()
{
	ArrayMain();
}