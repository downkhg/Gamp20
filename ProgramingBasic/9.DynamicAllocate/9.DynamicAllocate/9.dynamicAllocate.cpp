#include <stdio.h>
#include <stdlib.h>
//�����Ҵ�: ���α׷� �������� �޸𸮰� �Ҵ�Ǵ� ��. 
//�����Ҵ�: ���α׷�����(��Ÿ��)�߿� �޸𸮸� �Ҵ��ϴ� ��.
//void������: ����ִ�. Ÿ���̾��� ������
//�����Ҵ�� �޸𸮴� �����Ϸ��� �����Ҽ������Ƿ�, ���α׷��Ӱ� ���� ����������Ѵ�.
//����, ���������� �޸� ������ �߻��ϰԵȴ�.
//�����Ϳ� �����Ҵ�� �޸��� �ּҸ� ��������������. �����Ҽ������Ƿ� �ݵ�� �����Ͱ� �ʿ��ϴ�.
//���� �����Ҵ縸�ϰ� �ּҰ��� �������������� �� �޸𸮴� �ݵ�� �޸𸮴����� �ȴ�.
void DynamicAllocateMain()
{
	int* pData = new int();//(int*)malloc(sizeof(int)); //c
	*pData = 10;
	printf("pData[%d]:%d\n",pData, *pData);
	//�޸𸮻���
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
	//�޸𸮻���
	delete[] pData;
	//free(pData);
}
void main()
{
	DynamicAllocateMain();
	DynamicAllocateArrayMain();
}