#pragma once
#define NULL 0
#include<stdio.h>
namespace demo
{
	struct SNode {
		int nData;
		SNode* pNext;
	};
	class LinkedList
	{
	private:
		SNode* pBegin = NULL;
		SNode* pEnd = NULL;
	public:
		SNode* CreateNode(int data)
		{
			SNode* pTemp = NULL;

			pTemp = new SNode();
			pTemp->nData = data;
			pTemp->pNext = NULL;
			if (pEnd != NULL)//0x01 != NUUL -> T
				pEnd->pNext = pTemp; //실행되지않음
			//pTemp->pNext = pNode; //실행은 가능하지만 정상적인 결과가 아님.
			pEnd = pTemp;
			if (pBegin == NULL) pBegin = pEnd;
			return  pTemp;
		}

		SNode* FindNodeData(int data)
		{
			SNode* pNode = pBegin; //0x01

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

		SNode* InsertNodeData(int data, int insert)
		{
			SNode* pNode = pBegin;
			SNode* pInsert = NULL;

			pNode = FindNodeData(data);

			pInsert = new SNode();
			pInsert->nData = insert;
			pInsert->pNext = pNode->pNext;
			pNode->pNext = pInsert;


			return pNode;
		}

		void DeleteNodeData(int del)
		{
			SNode* pPre = NULL;
			SNode* pNode = pBegin;

			//pNode = FindNodeData(pStart, del); //이전값을 찾을 수 없다.
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

		void PrintLinkedList()
		{
			SNode* pNode = pBegin;
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

		void DeleteLinkedList()
		{
			SNode* pNode = pBegin;
			SNode* pDel = NULL;



		}
	};
}