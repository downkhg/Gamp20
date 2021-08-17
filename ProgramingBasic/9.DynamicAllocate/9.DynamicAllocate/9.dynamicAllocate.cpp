#include <stdio.h>
#include <stdlib.h>
//정적할당: 프로그램 실행전에 메모리가 할당되는 것. 
//동적할당: 프로그램실행(런타임)중에 메모리를 할당하는 것.
//void포인터: 비어있다. 타입이없는 포인터
//동적할당된 메모리는 컴파일러가 관리할수없으므로, 프로그래머가 직접 해제해줘야한다.
//만약, 하지않으면 메모리 누수가 발생하게된다.
//포인터에 동적할당된 메모리의 주소를 저장하지않으면. 접근할수없으므로 반드시 포인터가 필요하다.
//만약 동적할당만하고 주소값을 저장하지않으면 그 메모리는 반드시 메모리누수가 된다.
void DynamicAllocateMain()
{
	int* pData = new int();//(int*)malloc(sizeof(int)); //c
	*pData = 10;
	printf("pData[%d]:%d\n",pData, *pData);
	//메모리삭제
	delete pData; 
	//free(pData);//c
}
void DynamicAllocateArrayMain()
{
	int nSize;
	printf("ArraySize:");
	scanf("%d",&nSize);
	int* pData = new int[nSize];//(int*)malloc(sizeof(int) * nSize);
	for (int i = 0; i < nSize; i++)
	{
		pData[i] = i * 10;
		printf("pData[%d]:%d\n", i, pData[i]);
	}	
	//메모리삭제
	delete[] pData;
	//free(pData);
}
void main()
{
	DynamicAllocateMain();
	DynamicAllocateArrayMain();
}