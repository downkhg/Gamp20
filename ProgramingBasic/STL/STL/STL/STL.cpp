#include <iostream>
//선형자료구조
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
//트리자료구조
#include <set>
#include <map>
//해시테이블
#include <unordered_map>
using namespace std;
//백터: 동적배열 -> 크기를 변경할 수 있는 배열
//알고리즘 분석
//1.백터 정수형벡터 크기 1로 생성하고 10으로 초기화 한다.
//2.백터를 크기만큼 출력한다.
//3.배열의 크기를 3으로 늘려주고, 값을 출력한다.
//4. 추가, 삽입, 삭제, 모두삭제를 테스트한다.
//5. 4에 각 함수를 실행하고 출력하여 결과를 확인한다.
//6. 삽입은 이터레이터를 이용하므로 삽입전에 이터레이터를 에대하여 알아본다.
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
	container.push_back(99);//추가
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	vector<int>::iterator it = container.begin();//노드
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
	//노드기반 순차접근
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	it = it - 3;
	container.erase(it); //삭제
	container.pop_back(); //마지막원소삭제
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.clear(); //모두삭제
}
//데크: 양끝에서 추가 가능한 자료구조
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
	container.push_back(99);//추가
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	deque<int>::iterator it = container.begin();//노드
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
	//노드기반 순차접근
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	it = it - 3;
	container.erase(it); //삭제
	container.pop_back(); //마지막원소삭제
	container.pop_front(); //첫원소삭제
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;
	container.clear(); //모두삭제
}
//이중연결리스트
void ListMain()
{
	list<int> container(1);
	list<int>::iterator it = container.begin();//노드
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
	container.push_back(99);//추가
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
	//노드기반 순차접근
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	--it; --it; --it;
	container.erase(it); //삭제
	container.pop_back(); //마지막원소삭제
	for (it = container.begin(); it != container.end(); it++)
		cout << *it << ",";
	cout << endl;
	container.clear(); //모두삭제
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