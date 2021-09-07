/*##################################
이진트리(C언어 수업용)
파일명: BinaryTree.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2018.04.03
버전 : 1.00
###################################*/
#include <stdio.h>

using namespace std;

struct SNode {
	int nData;
	SNode* pLeft;
	SNode* pRight;
};

SNode* CreateNode(int data)
{
	SNode* pTemp = new SNode;
	pTemp->nData = data;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;
	return pTemp;
};
bool MakeLeft(SNode* pParant, SNode* pChilde)
{
	if (pParant == NULL)//0x01 == N -> F
		return false;
	pParant->pLeft = pChilde;
	return true;
};
bool MakeRight(SNode* pParant, SNode* pChilde)
{
	if (pParant == NULL)
		return false;
	pParant->pRight = pChilde;
	return true;
};

void Traverse(SNode* pNode)
{
	if (!pNode) return;
	//printf("%d\n", pNode->nData); //전위
	Traverse(pNode->pLeft);
	printf("%d\n", pNode->nData); //중위
	Traverse(pNode->pRight);
	//printf("%d\n", pNode->nData); //후위
}

void Print(SNode* pSeed)
{
	Traverse(pSeed);
}

void Swap(int& a, int& b)
{
	printf("Swap[%d <->%d]\n", a, b);
	int temp = a;
	a = b;
	b = temp;
}

void MinHipTreeInsert(SNode* pParent, SNode* pInsert)
{
	if (pParent == NULL) return;
	if (pParent->nData > pInsert->nData)
	{
		printf("Swap Parent\n");
		Swap(pParent->nData, pInsert->nData);

		MinHipTreeInsert(pParent, pInsert);
	}
	else
	{
		if (pParent->pLeft == NULL)
		{
			pParent->pLeft = pInsert;
			printf("MinHipTreeInsert_Left:%d\n", pInsert->nData);
			return;
		}
		else if (pParent->pRight == NULL)
		{
			pParent->pRight = pInsert;
			printf("MinHipTreeInsert_Right:%d\n", pInsert->nData);
			return;
		}
		else
			MinHipTreeInsert(pParent->pLeft, pInsert);
	}
}

void SetTestMain()
{
	const int nSize = 7;
	SNode* arrNode[nSize];

	for (int i = 0; i < nSize; i++)
		arrNode[i] = CreateNode((i + 1) * 10);

	SNode* pSeed = arrNode[3];
	
	MakeLeft(arrNode[3], arrNode[1]);
	MakeRight(arrNode[3], arrNode[5]);


	MakeLeft(arrNode[1], arrNode[0]);
	MakeRight(arrNode[1], arrNode[2]);

	MakeLeft(arrNode[5], arrNode[4]);
	MakeRight(arrNode[5], arrNode[6]);

	Print(pSeed);
}

void TreeBasicMain()
{
	SNode* pSeed = NULL;

	SNode* pParant = CreateNode(10);
	SNode* pLeft = CreateNode(20);
	SNode* pRight = CreateNode(30);
	SNode* pD = CreateNode(40);
	SNode* pE = CreateNode(50);

	if (!MakeLeft(pParant, pLeft))
		printf("MakeLeft Fail!!");
	MakeRight(pParant, pRight);

	MakeLeft(pLeft, pD);
	MakeRight(pLeft, pE);

	pSeed = pParant;

	Print(pSeed);
}

void main()
{
	SetTestMain();
}