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
//�迭���� �ּҰ��� ã�Ƽ� ����϶�.
//(�ּҰ�, �迭������ ���� ���� ���� ã�°�)
//������: 30,40,50,10,20, �ּҰ��� �˻��ϱ����� ������ ����
//�˰���: 
//���迭�� ���� ���ؼ� ���� ���� ���� �������� ã�´�.
//ù��°���� �����ϰ�, ����Ȱ����� ���� ���� ������ ���� �ּҰ����� ��ä�Ѵ�.
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
//�Լ��� �Ű������� �����Ҷ� �迭�� �̸��� �ּҰ��� �����Ƿ� �ּҰ��� ���޵ȴ�.
//�׷��Ƿ�, ������ ���氡���ϰԵȴ�.
void InitArray(int arr[], int size)
{
	printf("InitArray[%d]:%d\n",size,arr);
	for (int i = 0; i < size; i++)
		arr[i] = 100 - i * 10;
}
void PrintArray(int arr[], int size)
{
	printf("PrintArray[%d]:%d\n", size, arr);
	for (int i = 0; i < size; i++)
		printf("[%d/%d]%d,", &arr[i], i, arr[i]);
	printf("\n");
}
//�迭��� �����͸� �Ű������� �ᵵ �����ϴ�.
void PrintArray(const int* arr, int size, const char* msg)
{
	printf("PrintArray[%d]:%d\n", size, arr);
	printf("%s:",msg);
	for (int i = 0; i < size; i++)
		printf("[%d/%d]%d,", &arr[i], i, arr[i]);
	printf("\n");
}
//const�� ���̸� ������ ���� �����Ҽ������Ƿ�. ����� ����������� �����ϴ� �������� ��밡���ϴ�.
void CopyArray(int arrA[], const int arrB[], int size)
{
	printf("PrintArray[%d]:%d to %d\n", size, arrB, arrA);
	for (int i = 0; i < size; i++)
		arrA[i] = arrB[i];
		//arrB[i] = arrA[i]; //�����Ͽ���
}
void ArrayAndFunctionMain()
{
	const int nSize = 3;
	int arrScores[nSize];
	int nMemorySize = sizeof(arrScores);
	int nArraySize = nMemorySize / sizeof(arrScores[0]);
	printf("MemorySize/ArraySize:%d/%d\n", nMemorySize, nArraySize);
	printf("arrScore[%d]%d\n", &arrScores, arrScores);
	InitArray(arrScores, nSize);//�ʱ�ȭ
	PrintArray(arrScores, nSize);//�迭���
	PrintArray(arrScores, nSize, "PrintPtr");//�����͸� �����ص� ���������� Ȱ�밡���ϴ�.
	int arrCopyScore[nSize];
	printf("Score/CopyScore:%d/%d\n", arrCopyScore, arrScores);
	CopyArray(arrCopyScore,arrScores, nSize);//�迭����
}
void Array2DMain()
{
	const int nWidth = 5;
	const int nHeight = 3;
	int arr2DArray[nHeight][nWidth];
	int arrFake2DArray[nHeight * nWidth];
	for (int y = 0; y < nHeight; y++)
	{
		for (int x = 0; x < nWidth; x++)
		{
			int idx = nWidth * y + x; //5*0+0 = 0 //5*1+0 = 5 //5*2+0=10
			arrFake2DArray[idx] = x * y;
			arr2DArray[y][x] = x * y;
		}
	}
	printf("####### Array2D #######\n");
	for (int y = 0; y < nHeight; y++)
	{
		printf("[%d]%d-",y,arr2DArray[y]);
		for (int x = 0; x < nWidth; x++)
		{
			printf("%d[%d,%d]:%d, ", &arr2DArray[y][x], y, x, arr2DArray[y][x]);
		}
		printf("\n");
	}
	printf("####### ArrayFake2D #######\n");
	for (int y = 0; y < nHeight; y++)
	{
		for (int x = 0; x < nWidth; x++)
		{
			int idx = nWidth * y + x;
			printf("%d[%d,%d]:%d, ", &arrFake2DArray[idx], y, x, arrFake2DArray[idx]);
		}
		printf("\n");
	}
}
void main()
{
	//ArrayMain();
	//ArrayFindMinDataMain();
	//PointerMain();
	//FunctionAndPointerMain();
	//ArrayAndPointerMain();
	//ArrayAndFunctionMain();
	Array2DMain();
}