#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

struct SNode
{
	char cData;
	bool bVisit = false;
	list<SNode*>::iterator itChild;
	list<SNode*> listAdjacency;
	SNode(char data) { cData = data; }
};

void MakeAdjacency(SNode* pParent, SNode* pAdjacency)
{
	if (pParent)
	{
		pParent->listAdjacency.push_back(pAdjacency);
		pParent->itChild = pParent->listAdjacency.begin();
	}
}

void TravesseDFS(SNode* pNode)
{
	if (pNode->bVisit == false)
	{
		cout << pNode->cData << endl;
		pNode->bVisit = true;

		list<SNode*>::iterator it = pNode->listAdjacency.begin();
		for (; it != pNode->listAdjacency.end(); it++)
		{
			cout << "Adjacency:"<< (*it)->cData << endl;
			TravesseDFS(*it);
		}
	}
	else
		cout << "Revisit:" << pNode->cData << endl;
}

bool Visit(SNode* pNode, queue<SNode*>& visit)
{
	if (pNode)
	{
		if (pNode->bVisit == false)
		{
			cout << pNode->cData << endl;
			//cout << "Visit:" << pNode->cData << endl;
			pNode->bVisit = true;
			visit.push(pNode);
			return true;
		}
		else
		{
			//cout << "Revisit! " << visit.front()->cData << endl;
		}
	}
	return false;
}

void TraverBFS(SNode* pNode)
{
	queue<SNode*> visit;
	do
	{
		Visit(pNode, visit);

		list<SNode*>::iterator it = pNode->listAdjacency.begin();
		for (; it != pNode->listAdjacency.end(); it++)
		{
			SNode* pNode = *it;
			Visit(pNode, visit);
		}
		visit.pop();
		if (!visit.empty())
			pNode = visit.front();
	} 	while (!visit.empty());
}

void TraverReset(vector<SNode*>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i]->bVisit = false;
		vec[i]->itChild = vec[i]->listAdjacency.begin();
	}
}

SNode* VisitDFS(SNode* pNode, stack<SNode*>& visit)
{
	SNode* pNext = NULL;
	if (pNode)
	{
		if (pNode->bVisit == false)
		{
			//cout << "Visit:" << pNode->cData << endl;
			cout << pNode->cData << endl;
			visit.push(pNode);
			pNode->bVisit = true;
		}
		else
		{
			//cout << "Revisit:" << pNode->cData << endl;
		}
		//list<SNode*>::iterator it = pNode->itChild;
		if (pNode->listAdjacency.size() > 0)
		{
			if (pNode->itChild != pNode->listAdjacency.end())
			{
				pNext = *pNode->itChild;
				while (pNext != NULL && pNext->bVisit == true)
				{
					if (pNode->itChild != pNode->listAdjacency.end())
					{
						//cout << "Revisit!" << (*pNode->itChild)->cData << endl;
						pNext = *pNode->itChild;
						pNode->itChild++;
					}
					else
					{
						//cout << "Visit Complete!" << pNode->cData << endl;
						pNext = NULL;
					}
				}
			}
		}
	}
	else
	{
		//cout << "Visit Complete! " << visit.top()->cData << endl;
		visit.pop();
		if (!visit.empty())
			pNext = visit.top();
	}
	return pNext;
}

void TraverDFSStack(SNode* pNode)
{
	stack<SNode*> visit;
	do
	{
		pNode = VisitDFS(pNode, visit);
	} 	while (!visit.empty());
}

enum E_NODE { A, B, C, D, E, F, G, H, MAX} ;

void main()
{
	vector<SNode*> vecNodes(MAX);

	for (int i = 0; i < vecNodes.size(); i++)
	{
		vecNodes[i] = new SNode('A'+i);
	}

	MakeAdjacency(vecNodes[A], vecNodes[B]);

	MakeAdjacency(vecNodes[B], vecNodes[D]);
	MakeAdjacency(vecNodes[B], vecNodes[F]);

	MakeAdjacency(vecNodes[C], vecNodes[B]);

	MakeAdjacency(vecNodes[D], vecNodes[H]);

	MakeAdjacency(vecNodes[E], vecNodes[C]);
	MakeAdjacency(vecNodes[E], vecNodes[H]);

	MakeAdjacency(vecNodes[F], vecNodes[D]);
	MakeAdjacency(vecNodes[F], vecNodes[G]);
	MakeAdjacency(vecNodes[F], vecNodes[H]);

	MakeAdjacency(vecNodes[G], vecNodes[E]);
	MakeAdjacency(vecNodes[G], vecNodes[F]);
	MakeAdjacency(vecNodes[G], vecNodes[H]);

	//TravesseDFS(vecNodes[A]);
	TraverDFSStack(vecNodes[A]);
	//TraverBFS(vecNodes[A]);
	TraverReset(vecNodes);

	for (int i = 0; i < vecNodes.size(); i++)
		delete vecNodes[i];

	vecNodes.clear();
}