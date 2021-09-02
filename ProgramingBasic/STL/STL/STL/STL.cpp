#include <iostream>
//�����ڷᱸ��
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
//Ʈ���ڷᱸ��
#include <set>
#include <map>
//�ؽ����̺�
#include <unordered_map>
using namespace std;
//����: �����迭 -> ũ�⸦ ������ �� �ִ� �迭
//�˰��� �м�
//1.���� ���������� ũ�� 1�� �����ϰ� 10���� �ʱ�ȭ �Ѵ�.
//2.���͸� ũ�⸸ŭ ����Ѵ�.
//3.�迭�� ũ�⸦ 3���� �÷��ְ�, ���� ����Ѵ�.
//4. �߰�, ����, ����, ��λ����� �׽�Ʈ�Ѵ�.
//5. 4�� �� �Լ��� �����ϰ� ����Ͽ� ����� Ȯ���Ѵ�.
//6. ������ ���ͷ����͸� �̿��ϹǷ� �������� ���ͷ����͸� �����Ͽ� �˾ƺ���.
void VectorMain()
{
	vector<int> container(1);
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout<<"["<<i<<"]" <<container[i]<<",";
	cout << endl;
	container.resize(3);
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.push_back(99);//�߰�
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	vector<int>::iterator it = container.begin();//���
	cout << "begin:" <<*it << endl;
	cout << "begin+2:" << *(it+2) << endl;
	it = container.insert(it, 88);
	if (it != container.end())
		cout << "Insert:" << *it << endl;
	else
		cout << "Insert is null" << endl;
	it = --container.end();
	if (it != container.end())
		cout << "end-1:" << *it << endl;
	else
		cout << "it is null" << endl;
	it = container.insert(it, 77);
	//����� ��������
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	it = it - 3;
	container.erase(it); //����
	container.pop_back(); //���������һ���
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.clear(); //��λ���
}
//��ũ: �糡���� �߰� ������ �ڷᱸ��
void DequeMain()
{
	deque<int> container(1);
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.resize(3);
	container[1] = 20;
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.push_front(11);
	container.push_back(99);//�߰�
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	deque<int>::iterator it = container.begin();//���
	cout << "begin:" << *it << endl;
	cout << "begin+2:" << *(it + 2) << endl;
	it = container.insert(it, 88);
	if (it != container.end())
		cout << "Insert:" << *it << endl;
	else
		cout << "Insert is null" << endl;
	it = --container.end();
	if (it != container.end())
		cout << "end-1:" << *it << endl;
	else
		cout << "it is null" << endl;
	it = container.insert(it, 77);
	//����� ��������
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	it = it - 3;
	container.erase(it); //����
	container.pop_back(); //���������һ���
	container.pop_front(); //ù���һ���
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.clear(); //��λ���
}
//���߿��Ḯ��Ʈ
void ListMain()
{
	list<int> container(1);
	list<int>::iterator it = container.begin();//���
	*it = 10;
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.resize(3);
	it = container.begin(); it++; it++;
	*it = 20;
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.push_back(99);//�߰�
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	it = container.begin();
	cout << "begin:" << *it << endl;
	it++; it++;
	cout << "begin+2:" << *it << endl;
	it = container.insert(it, 88);
	if (it != container.end())
		cout << "Insert:" << *it << endl;
	else
		cout << "Insert is null" << endl;
	it = --container.end();
	if (it != container.end())
		cout << "end-1:" << *it << endl;
	else
		cout << "it is null" << endl;
	it = container.insert(it, 77);
	//����� ��������
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	--it; --it; --it;
	container.erase(it); //����
	container.pop_back(); //���������һ���
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.clear(); //��λ���
}

void QueueMain()
{
	queue<int> container;

	container.push(10);
	container.push(50);
	container.push(20);
	container.push(30);
	container.push(60);

	while (container.empty() == false)
	{
		cout << container.front() << endl;
		container.pop();
	}
}

void StatckMain()
{
	stack<int> container;

	container.push(10);
	container.push(50);
	container.push(20);
	container.push(30);
	container.push(60);

	while (container.empty() == false)
	{
		cout << container.top() << endl;
		container.pop();
	}
}

void PriorityQuequeMain()
{
	priority_queue<int> container;

	container.push(10);
	container.push(50);
	container.push(20);
	container.push(30);
	container.push(60);

	while (container.empty() == false)
	{
		cout << container.top() << endl;
		container.pop();
	}
}

void SetMain()
{
	set<int> container;

	for (int i = 0; i < 7; i++)
	{
		container.insert((i+1)*10);
	}

	set<int>::iterator it = container.begin();
	for (; it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
}

void MapMain()
{
	map<int, string> container;

	container[0] = "Zero";
	container[1] = "One";
	container[2] = "Two";
	container[3] = "Three";
	container[4] = "Four";
	container[5] = "Five";
	container[6] = "Six";

	for (int i = 0; i < container.size(); i++)
	{
		cout << i << ":" << container[i] << ",";
	}
	cout << endl;

	map<int, string>::iterator it = container.begin();
	for (; it != container.end(); it++)
		cout << it->first << ":"<< it->second << ",";
	cout << endl;
}

void HashMapMain()
{
	unordered_map<int, string> container;

	container[0] = "Zero";
	container[1] = "One";
	container[2] = "Two";
	container[3] = "Three";
	container[4] = "Four";
	container[5] = "Five";
	container[6] = "Six";

	for (int i = 0; i < container.size(); i++)
	{
		cout << i << ":" << container[i] << ",";
	}
	cout << endl;
}

void main()
{
	//VectorMain();
	//DequeMain();
	//ListMain();
	//QueueMain();
	//StatckMain();
	//PriorityQuequeMain();
	//SetMain();
	MapMain();
}