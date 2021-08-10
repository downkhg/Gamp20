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
	//���ϰ� (*�����͸�)(�Ű�����,�Ű躯��): ���ϰ�, �Ű躯���� ������ Ÿ���� ���ƾ��Ѵ�.
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
//��Ģ������ ������ 3���� �Ű������� �Ǽ��� �޾� ����ϴ� ���α׷� �ۼ��ϱ�
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