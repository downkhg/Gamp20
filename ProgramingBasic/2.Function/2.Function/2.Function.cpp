#include <stdio.h>
//��ȯ��: �Լ����� �ѱ�Ե� ���� ����.
//�Ű�����: �Լ��ܺ��� ���� �������ִ� ����.
//�Լ����̸�: �Լ��Ǳ�ɿ� �°� �����ش�.
//��ȯ�� �Լ���(�Ű�����,...)
int Add(int a, int b)//10,20
{
	return a + b;//��ȯ��. //30
}

float Add(float a, float b)//10,20
{
	return a + b;//��ȯ��. //30
}

void AddTestMain()
{
	//�μ�: �Ű������� ������ ��.
	int nResult = Add(10, 20); //30
	float fResult = Add(3.15f, 2.5f); //5.65
	printf("Result:%d/%f\n",nResult,fResult);//Result:30/5.65
}

//�Լ��� ����:�̷��Լ��� �ִٴ°��� �̸� �����Ϸ����� �˸�.
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
//�Լ��� ����:������ �Լ��� ��ü�� ����.
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