#include <stdio.h>
int g_nDataEx; 
static int g_nStaticDataEx;//정적전역변수:파일이 다르면 접근할수없는 전역변수.

static void SetStaticDataEx(int data)//정적함수는 해당파일에서만 접근가능하다.
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