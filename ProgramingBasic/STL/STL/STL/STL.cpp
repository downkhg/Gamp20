#include <iostream>
#include <vector>
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
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.clear(); //��λ���
}

void main()
{
	VectorMain();
}