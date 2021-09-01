/*##################################
����Ʈ��(C��� ������)
���ϸ�: BinaryTree.cpp
�ۼ��� : ��ȫ��(downkhg@gmail.com)
������������¥ : 2018.04.03
���� : 1.00
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
	//printf("%d\n", pNode->nData); //����
	Traverse(pNode->pLeft);
	//printf("%d\n", pNode->nData); //����
	Traverse(pNode->pRight);
	printf("%d\n", pNode->nData); //����
}

void Print(SNode* pSeed)
{
	Traverse(pSeed);
}

void main()
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