#include <stdio.h>
int g_nDataEx; 
static int g_nStaticDataEx;//������������:������ �ٸ��� �����Ҽ����� ��������.

static void SetStaticDataEx(int data)//�����Լ��� �ش����Ͽ����� ���ٰ����ϴ�.
{
	g_nStaticDataEx = data;
}

void PrintDataEx()
{
	printf("DataEx:%d\n",g_nDataEx);
}

void PrintStaticDataEx()
{
	printf("DataStaticEx:%d\n", g_nStaticDataEx);
}