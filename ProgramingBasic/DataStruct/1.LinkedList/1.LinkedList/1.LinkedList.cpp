/*##################################
���Ͽ��Ḯ��Ʈ(������)
���ϸ�: LinkedList_empty.cpp
�ۼ���: ��ȫ�� (downkhg@gmail.com)
������������¥: 2019.04.12
����: 1.10
###################################*/

#include <stdio.h>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���
//#include  "linkedlistClass.h"
#include "LinkedList.h"

struct SNode {
	int nData;
	SNode* pNext;
};

SNode* CreateNode(SNode* pNode, int data); //��带 �����Ͽ� �����Ѵ�.
SNode* FindNodeData(SNode* pStart, int data); //�ش� �����͸� ���� ��带 ã�´�.
SNode* InsertNodeData(SNode* pStart, int data, int insert); //�ش� �����͸� ���� ��� �ڿ� ��带 �߰��Ѵ�.
void DeleteNodeData(SNode* pStart, int del); //�ش絥���͸� ���� ��带 �����Ѵ�.
void PrintLinkedList(SNode* pStart); //��带 ��ȸ�ϸ� ���������� ����Ѵ�.
//void DeleteLinkedList(SNode** pStart); //��带 ��ȸ�ϸ� ��絥���͸� �����Ѵ�.
void DeleteLinkedList(SNode* &pStart); //��带 ��ȸ�ϸ� ��絥���͸� �����Ѵ�.
void ReverseLinkedList(SNode* pStart); //

									   //���Ḯ��Ʈ �������� �Է¹ޱ�.(�����Ҵ� �����)
void InputAdd();

//�����۵� �׽�Ʈ�� ���ؼ�, ������ ���� �⺻���� ������ ������ Ȯ���Ѵ�.
//�� �ҽ��� ��� ���װ� �����Ѵ�.
//�� �ڵ尡 �����۵� �� �� �߰��غ���!
//main()�Լ� �� �ڵ�� �߰��� ���������� ������ ��������!
void LinkedListMain()
{
	//_CrtSetBreakAlloc(71); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	SNode* pBegin = NULL;
	SNode* pEnd = NULL;

	//��� �߰� �׽�Ʈ
	pEnd = CreateNode(pEnd, 10);
	pBegin = pEnd; //������ ��带 �˾ƾ� �˻��� �����ϹǷ� �����صд�.

	pEnd = CreateNode(pEnd, 20);
	pEnd = CreateNode(pEnd, 30);
	pEnd = CreateNode(pEnd, 40);
	pEnd = CreateNode(pEnd, 50);

	PrintLinkedList(pBegin);

	SNode* pFind = FindNodeData(pBegin, 40);
	if (pFind != NULL)
		printf("Find:%d\n", pFind->nData);

	pEnd = InsertNodeData(pBegin, 30, 60);//��� ����

	PrintLinkedList(pBegin);

	DeleteNodeData(pBegin, 60);//��� ����

	PrintLinkedList(pBegin);

	DeleteLinkedList(pBegin); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.
}

void LinkedListTestMain()
{
	//_CrtSetBreakAlloc(71); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 
	demo::LinkedList cLinkedList;

	//��� �߰� �׽�Ʈ
	cLinkedList.CreateNode(10);
	cLinkedList.CreateNode(20);
	cLinkedList.CreateNode(30);
	cLinkedList.CreateNode(40);
	cLinkedList.CreateNode(50);

	cLinkedList.PrintLinkedList();

	demo::SNode* pFind = cLinkedList.FindNodeData(40);
	if (pFind != NULL)
		printf("Find:%d\n", pFind->nData);

	cLinkedList.InsertNodeData(30, 60);//��� ����

	cLinkedList.PrintLinkedList();

	cLinkedList.DeleteNodeData(60);//��� ����

	cLinkedList.PrintLinkedList();

	cLinkedList.DeleteLinkedList(); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.
}

void main()
{
	LinkedListTestMain();
}

//���⼭ ���� ����� �����Ѵ�.
//�����ڵ�� �մ�������, �߰��� �Ͽ� �� ���α׷� ���� �۵��ϵ����Ұ�.
SNode* CreateNode(SNode* pNode, int data)
{
	SNode* pTemp = NULL;

	pTemp = new SNode();
	pTemp->nData = data;
	pTemp->pNext = NULL;
	if(pNode != NULL)//0x01 != NUUL -> T
		pNode->pNext = pTemp; //�����������
	//pTemp->pNext = pNode; //������ ���������� �������� ����� �ƴ�.
	return  pTemp;
}

SNode* FindNodeData(SNode* pStart, int data)
{
	SNode* pNode = pStart; //0x01

	while (true)
	{
		if (pNode->nData != data)//20 != 40 -> T
		{
			pNode = pNode->pNext;
		}
		else
			break;
	}

	return pNode;
}

SNode* InsertNodeData(SNode* pStart, int data, int insert)
{
	SNode* pNode = pStart;
	SNode* pInsert = NULL;

	pNode = FindNodeData(pStart, data);
	
	pInsert = new SNode();
	pInsert->nData = insert;
	pInsert->pNext = pNode->pNext;
	pNode->pNext = pInsert;
	

	return pNode;
}

void DeleteNodeData(SNode* pStart, int del)
{
	SNode* pPre = NULL;
	SNode* pNode = pStart;

	//pNode = FindNodeData(pStart, del); //�������� ã�� �� ����.
	while (pNode)
	{
		if (pNode->nData == del)//60 == 60 -> T
		{
			pPre->pNext = pNode->pNext;
			delete pNode;
			break;
		}
		else
		{
			pPre = pNode;
			pNode = pNode->pNext;
			//pPre = pStart;
		}
	}
}

void PrintLinkedList(SNode* pStart)
{
	SNode* pNode = pStart;
	printf("data:");
	while (pNode)
	{
		printf("%d", pNode->nData);
		pNode = pNode->pNext;

		if (pNode != NULL)
			printf(",");
	}
	printf("\n");
}

void DeleteLinkedList(SNode* &pStart)
{
	SNode* pNode = pStart;
	SNode* pDel = NULL;

	

}

//����������: �������� �ּҰ��� �����ϴ� ����
//void DeleteLinkedList(SNode** pStart)
//{
//	SNode* pNode = *pStart;
//	SNode* pDel = NULL;
//
//	while (pNode)
//	{
//		//delete pNode;
//		pDel = pNode;
//		pNode = pNode->pNext;
//		delete pDel;
//	}
//	*pStart = NULL;
//}

void InputAdd()
{
	SNode* pStart = NULL;
	SNode* pNode = NULL;
	int nData = 0;

	//�����Ҵ��� �ϸ� ���α׷��� ����ڿ� ���ؼ� ���Ǵ� �޸𸮰� �����ȴ�.
	//���Ը��ؼ�, �����ϴܰ迡�� 100���� ����� ���ٸ�, 
	//��������ʴ��� 100���� �޸𸮸� ����Ҽ��ۿ�����.
	//�׸���, 100�� �̻��� �޸𸮵� ����Ҽ�����.
	//�׷���, �����Ҵ��� �ϸ� ����ڰ� �߰��� �޸𸮸�ŭ�� �޸𸮰� ���ǰ� 
	//�޸𸮿뷮�� ����ϴ� �� �߰��� �ȴ�.
	while (nData != -1)
	{
		scanf("%d", &nData);
		pNode = CreateNode(pNode, nData);

		if (pNode == NULL)
		{
			printf("�� �̻� ����Ҽ� �ִ� �޸𸮰� �����ϴ�!");
		}

		if (pStart == NULL)
			pStart = pNode;

		PrintLinkedList(pStart);
	}

	DeleteLinkedList(pStart); //�������� - �� �Լ��� ȣ������������ �޸𸮰� ������.
}