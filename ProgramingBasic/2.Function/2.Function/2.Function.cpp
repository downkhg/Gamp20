#include <stdio.h>
//반환형: 함수에서 넘기게될 값의 종류.
//매개변수: 함수외부의 값을 전달해주는 변수.
//함수의이름: 함수의기능에 맞게 지어준다.
//반환형 함수명(매개변수,...)
int Add(int a, int b)//10,20
{
	return a + b;//반환값. //30
}

float Add(float a, float b)//10,20
{
	return a + b;//반환값. //30
}

void AddTestMain()
{
	//인수: 매개변수에 전달할 값.
	int nResult = Add(10, 20); //30
	float fResult = Add(3.15f, 2.5f); //5.65
	printf("Result:%d/%f\n",nResult,fResult);//Result:30/5.65
}

//함수의 선언:이런함수가 있다는것을 미리 컴파일러에게 알림.
int Combination(int n, int r);
int Factorial(int n);

int CombinationTestMain(void)
{
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);
	printf("C(%d, %d) = %d \n", a, b, Combination(a, b));
	return 0;
}
//함수의 정의:선언한 함수의 실체를 만듦.
int Factorial(int n)
{
	int i;
	long result = 1;

	for (i = 1; i <= n; i++)
		result *= i;
	return result;
}

int Combination(int n, int r)
{
	int a = Factorial(n);
	int b = Factorial(r);
	int c = Factorial(n - r);
	return (a / b * c);
}

void main()
{
	//AddTestMain();
	CombinationTestMain();
}