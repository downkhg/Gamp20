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
//함수를 매개변수로 전달할때 배열의 이름은 주소값을 가지므로 주소값이 전달된다.
//그러므로, 원본을 변경가능하게된다.
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
//배열대신 포인터를 매개변수로 써도 무관하다.
void PrintArray(const int* arr, int size, const char* msg)
{
	printf("PrintArray[%d]:%d\n", size, arr);
	printf("%s:",msg);
	for (int i = 0; i < size; i++)
		printf("[%d/%d]%d,", &arr[i], i, arr[i]);
	printf("\n");
}
//const를 붙이면 원본의 값을 변경할수없으므로. 복사시 원본대상인지 구별하는 수단으로 사용가능하다.
void CopyArray(int arrA[], const int arrB[], int size)
{
	printf("PrintArray[%d]:%d to %d\n", size, arrB, arrA);
	for (int i = 0; i < size; i++)
		arrA[i] = arrB[i];
		//arrB[i] = arrA[i]; //컴파일오류
}
void ArrayAndFunctionMain()
{
	const int nSize = 3;
	int arrScores[nSize];
	int nMemorySize = sizeof(arrScores);
	int nArraySize = nMemorySize / sizeof(arrScores[0]);
	printf("MemorySize/ArraySize:%d/%d\n", nMemorySize, nArraySize);
	printf("arrScore[%d]%d\n", &arrScores, arrScores);
	InitArray(arrScores, nSize);//초기화
	PrintArray(arrScores, nSize);//배열출력
	PrintArray(arrScores, nSize, "PrintPtr");//포인터를 응용해도 다음과같이 활용가능하다.
	int arrCopyScore[nSize];
	printf("Score/CopyScore:%d/%d\n", arrCopyScore, arrScores);
	CopyArray(arrCopyScore,arrScores, nSize);//배열복사
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