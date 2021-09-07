#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct SNode
{
	char cData;
	bool bVisit = false;
	list<SNode*> listAdjacency;
	SNode(char data) { cData = data; }
};

void MakeAdjacency(SNode* pParent, SNode* pAdjacency)
{
	if (pParent)
	{
		pParent->listAdjacency.push_back(pAdjacency);
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
			TravesseDFS(*it);
		}
	}
}

void TraverReset(vector<SNode*>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i]->bVisit = false;
	}
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

	TravesseDFS(vecNodes[A]);
	TraverReset(vecNodes);

	for (int i = 0; i < vecNodes.size(); i++)
		delete vecNodes[i];

	vecNodes.clear();
}