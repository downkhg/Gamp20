#include <stdio.h>
#include <string.h>

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
	int arrData[5] = { 30,40,50,10,20 };
	int nMin = arrData[0];

	for(int i = 0; i<5; i++)
	{
		if (nMin > arrData[i])
		{
			nMin = arrData[i];
		}
	}
	printf("Min:%d\n",nMin);
}

void PointerMain()
{
	int nData = 10;
	int* pData = &nData;
	printf("1.nData:%d/%d\n",&nData,nData);
	printf("1.pData:%d/%d\n", pData, *pData);
	nData = 20;
	printf("2.nData:%d/%d\n", &nData, nData);
	printf("2.pData:%d/%d\n", pData, *pData);
	*pData = 30;
	printf("3.nData:%d/%d\n", &nData, nData);
	printf("3.pData:%d/%d\n", pData, *pData);
	pData++;
	printf("4.nData:%d/%d\n", &nData, nData);
	printf("4.pData:%d/%d\n", pData, *pData);
	pData--;
	printf("5.nData:%d/%d\n", &nData, nData);
	printf("5.pData:%d/%d\n", pData, *pData);

}

void SwapVal(int a, int b)
{
	printf("SwapVal[%d]%d<->[%d]%d\n",&a,a,&b,b);
	int temp = a;
	a = b;
	b = temp;
}
void SwapPtr(int* pA, int* pB)
{
	printf("SwapVal[%d]%d<->[%d]%d\n", pA, *pA, pB, *pB);
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}
void SwapRef(int& a, int& b)
{
	printf("SwapRef[%d]%d<->[%d]%d\n", &a, a, &b, b);
	int temp = a;
	a = b;
	b = temp;
}
void FunctionAndPointerMain()
{
	int nDataA = 10;
	int nDataB = 20;
	printf("Origin[%d]%d<->[%d]%d\n",&nDataA,nDataA,&nDataB,nDataB);
	SwapVal(nDataA, nDataB);
	printf("SwapVal[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapPtr(&nDataA, &nDataB);
	printf("SwapPtr[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapRef(nDataA, nDataB);
	printf("SwapRef[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
}

void ArrayAndPointerMain()
{
	const int nSize = 3;
	int arrScores[nSize];
	int nMemorySize = sizeof(arrScores);
	int nArraySize = nMemorySize / sizeof(arrScores[0]);
	printf("MemorySize/ArraySize:%d/%d\n", nMemorySize, nArraySize);
	printf("arrScore[%d]%d\n", &arrScores, arrScores);
	for (int i = 0; i < nArraySize; i++)
		arrScores[i] = i * 100 - i * 10;
	printf("\n");
	for (int i = 0; i < nArraySize; i++)
		printf("[%d/%d]%d,", &arrScores[i], i, arrScores[i]);
	printf("\n");

	for (int i = 0; i < nArraySize; i++)
		printf("[%d/%d]%d,", (arrScores + i), i, *(arrScores + i));
	printf("\n");

	int* pScore = arrScores;
	for (int i = 0; i < nArraySize; i++)
	{
		printf("[%d/%d]%d,", pScore, i, *pScore);
		pScore++;
	}
	printf("\n");

	int arrCopyScore[nSize];
	//arrCopyScore = arrScores;
	printf("Score/CopyScore:%d/%d\n", arrCopyScore, arrScores);
	for (int i = 0; i < nSize; i++)
		arrCopyScore[i] = arrScores[i];
	memcpy(arrCopyScore, arrScores, sizeof(arrCopyScore));
}

void main()
{
	//ArrayMain();
	//ArrayFindMinDataMain();
	//PointerMain();
	//FunctionAndPointerMain();
	ArrayAndPointerMain();
}