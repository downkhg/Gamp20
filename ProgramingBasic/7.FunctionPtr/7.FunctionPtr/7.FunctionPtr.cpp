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
	//리턴값 (*포인터명)(매개변수,매계변수): 리턴값, 매계변수의 개수와 타입이 같아야한다.
	int (*pfn)(int, int);

	pfn = Add;
	printf("Add[%d]:%d\n", pfn, pfn(10, 20));
	pfn = Sub;
	printf("Sub[%d]:%d\n", pfn, pfn(10, 20));
	pfn = Multiple;
	printf("Multiple[%d]:%d\n", pfn, pfn(10, 20));
	pfn = Div;
	printf("Div[%d]:%d\n", pfn, pfn(10, 20));
}

void EmptyMain()
{
	printf("EmptyMain!\n");
}
//사칙연산이 가능한 3개의 매개변수를 실수로 받아 계산하는 프로그램 작성하기
void CaculatorMain()
{

}
void main()
{
	void (*pMain)();
	pMain = FuncPtrTestMain;
	pMain();
	pMain = EmptyMain;
	pMain();
}