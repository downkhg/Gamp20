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

void main()
{
	//VectorMain();
	DequeMain();
}