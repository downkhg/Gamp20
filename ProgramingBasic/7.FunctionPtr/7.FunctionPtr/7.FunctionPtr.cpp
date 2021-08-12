#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Multiple(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}
//함수포인터: 함수의 주소값을 저장하는 변수 -> 함수도 주소가 있다.
void FuncPtrTestMain()
{
	//리턴값 (*포인터명)(매개변수,매개변수): 리턴값, 매개변수의 개수와 타입이 같아야한다.
	int (*pfn)(int, int);

	pfn = Add;
	printf("Add[%d]:%d\n", pfn, pfn(10, 20));//30
	pfn = Sub;
	printf("Sub[%d]:%d\n", pfn, pfn(10, 20));//-10
	pfn = Multiple;
	printf("Multiple[%d]:%d\n", pfn, pfn(10, 20));//200
	pfn = Div;
	printf("Div[%d]:%d\n", pfn, pfn(10, 20));//0
}

float Add(float a, float b, float c)
{
	return a + b + c;
}

float Sub(float a, float b, float c)
{
	return a - b - c;
}

float Multiple(float a, float b, float c)
{
	return a * b * c;
}

float Div(float a, float b, float c)
{
	return a / b / c;
}

//사칙연산이 가능한 3개의 매개변수를 실수로 받아 계산하는 프로그램 작성하기
void CaculatorMain()
{
	//리턴값 (*포인터명)(매개변수,매개변수,매개변수): 리턴값, 매계변수의 개수와 타입이 같아야한다.
	float (*pFn)(float,float, float);

	pFn = Add;
	printf("Add[%d]:%f\n",pFn, pFn(10, 20, 30)); //60
	pFn = Sub;
	pFn(10, 20, 30);
	printf("Sub[%d]:%f\n", pFn, pFn(10, 20, 30)); //-40
	pFn = Multiple;
	pFn(10, 20, 30);
	printf("Multiple[%d]:%f\n", pFn, pFn(10, 20, 30)); //6000
	pFn = Div;
	pFn(10, 20, 30);
	printf("Div[%d]:%f\n", pFn, pFn(10, 20, 30));//0.016
}

void EmptyMain()
{
	printf("EmptyMain!\n");
}

void main()
{
	void (*pMain)();
	pMain = FuncPtrTestMain;
	pMain();
	pMain = CaculatorMain;
	pMain();
	pMain = EmptyMain;
	pMain();
}