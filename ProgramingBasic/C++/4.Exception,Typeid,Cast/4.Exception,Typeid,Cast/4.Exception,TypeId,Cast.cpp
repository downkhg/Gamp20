#include <iostream>
using namespace std;
//피자조각수와 사람수를 입력받아 
//한사람이 몇 조각을 먹을수있는지
//계산하는 프로그램.
//데이터: 피자조각수, 사람수, 한사람당 피자조각수
//알고리즘: 피자조각수/사람수 = 한사람당 피자조각수
void PizzaSiliceMain()
{
	int nPizzaSlice; //?
	int nPersons; //?
	int nSlicePerPerson; //?

	cout << "피자조각수:";
	cin >> nPizzaSlice;//0
	cout << "사람수:";
	cin >> nPersons;//10

	try
	{
		if (nPizzaSlice <= 0) //0 <= 0 -> T
			throw "피자수가 너무 적습니다!";
		else if (nPersons <= 0)
			throw "사람이 없습니다!";

		nSlicePerPerson = nPizzaSlice / nPersons;

		cout << "피자조각/사람수 = " << nSlicePerPerson << endl;
	}
	//쓰로우된 형식에 따라 케치가 된다.
	catch(const char* e)
	{
		cout << e;//피자수가 너무 적습니다!
	}
}
//다형성: 부모포인터에서 자식객체를 할당하여 사용하는 것.
//try catch에서 다형성도 작동을 할것인가?
class Parent {
public:
	virtual void Display() { cout << "Parent" << endl; }
};
class ChildA : public Parent
{
public:
	void Display() override { cout << "ChildA" << endl; };
};
class ChildB : public Parent
{
public:
	void Display() override { cout << "ChildB" << endl; };
};
//예외처리에서도 다형성이 성립한다. 
void PolymorphismExceptionMain()
{
	Parent* pParent = new ChildB();
	ChildA cChildA;
	ChildB cChildB;

	try {
		//throw  pParent;
		throw cChildA;
	}
	//catch문법은 타입에 맞게 호출된다.
	catch (Parent& e)
	{
		e.Display();
	}
	catch (Parent* e)
	{
		e->Display();
	}

	delete pParent;
}
//다형성관계에서 부모가 어떤 타입인지 알아낼수있는 함수.
//다형성에서는 객체가 어떤것이 할당되어있는지 알기어렵다.
//그러므로, 다음과 같이 할당된객체를 판단할수있다면 쉽게 오류를 진단할수있다.
void TypeIdMain()
{
	Parent* pParentA = new ChildA();
	Parent* pParentB = new ChildB();

	cout << "ParentA:" << typeid(pParentA).name() << endl; //class Parent
	cout << "ParentB:" << typeid(pParentB).name() << endl; //class Parent

	cout << "ParentA*:" << typeid(*pParentA).name() << endl; //class ChildA
	cout << "ParentB*:" << typeid(*pParentB).name() << endl; //class ChildB

	delete(pParentA);
	delete(pParentB);
}
//정적할당된 변수를 캐스팅하는데 사용함.
//변환이 불가능한 형식을 사용하면 컴파일에러가남.
void StaticCastMain()
{
	int nDataCost = (int)3.14f; //3
	int nDataStaticCast = static_cast<int>(3.14f); //3

	int* pIntCast = static_cast<int*>(&nDataCost); //3?
	////포인터값을 받아서 다른타입으로 변환을 수행하면 오류가 난다.
	//float* pfloatCast = static_cast<int*>(&nDataCost);//컴파일오류

	cout << "DataCost:" << nDataCost << endl; //3
	cout << "DataStaticCast:" << nDataStaticCast << endl; //3?
}
//동적할당변수/객체
void DynamicCastMain()
{
	int* pIntData = new int();
	float* pfloatDataCast = (float*)pIntData;
	//일반멤버의 변수에는 사용할수없음.
	//float* pfloatDataDynamicCast = dynamic_cast<float*>(pIntData);
	delete pIntData;

	Parent* pParent = new Parent();
	ChildA* pChildA = new ChildA();
	ChildA* pParentToChildCast = (ChildA*)pParent;
	//부모->자식: 문제O
	ChildA* pParentToChildDynamicCast = dynamic_cast<ChildA*>(pParent);
	//자식->부모: 문제X
	Parent* pChildToParentDynamicCast = dynamic_cast<Parent*>(pChildA);
	//다음과 같이 문제가 있는 경우의 변환일경우 캐스팅이되지않고 null을 반환한다.
	cout << "pParentToChildDynamicCast:" << (int)pParentToChildDynamicCast << endl; //0 -> NULL
	cout << "pChildToParentDynamicCast:" << (int)pChildToParentDynamicCast << endl;
	delete pParent;
	delete pChildA;
}


void main()
{
	//PizzaSiliceMain();
	//PolymorphismExceptionMain();
	//TypeIdMain();
	//StaticCastMain();
	DynamicCastMain();
}