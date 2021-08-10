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
//�Լ�������: �Լ��� �ּҰ��� �����ϴ� ���� -> �Լ��� �ּҰ� �ִ�.
void FuncPtrTestMain()
{
	//���ϰ� (*�����͸�)(�Ű�����,�Ű�����): ���ϰ�, �Ű������� ������ Ÿ���� ���ƾ��Ѵ�.
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

//��Ģ������ ������ 3���� �Ű������� �Ǽ��� �޾� ����ϴ� ���α׷� �ۼ��ϱ�
void CaculatorMain()
{
	//���ϰ� (*�����͸�)(�Ű�����,�Ű�����,�Ű�����): ���ϰ�, �Ű躯���� ������ Ÿ���� ���ƾ��Ѵ�.
	float (*pFn)(float,float, float);

	pFn = Add;
	printf("Add[%d]:%f\n",pFn, pFn(10, 20, 30));
	pFn = Sub;
	pFn(10, 20, 30);
	printf("Sub[%d]:%f\n", pFn, pFn(10, 20, 30));
	pFn = Multiple;
	pFn(10, 20, 30);
	printf("Multiple[%d]:%f\n", pFn, pFn(10, 20, 30));
	pFn = Div;
	pFn(10, 20, 30);
	printf("Div[%d]:%f\n", pFn, pFn(10, 20, 30));
}

void main()
{
	void (*pMain)();
	pMain = FuncPtrTestMain;
	pMain();
	pMain = EmptyMain;
	pMain();
	pMain = CaculatorMain;
	pMain();
}