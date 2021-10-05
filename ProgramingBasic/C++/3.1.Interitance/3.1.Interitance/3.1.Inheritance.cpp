#include <iostream>
#include "Car.h"
#include "InheritanceCar.h"
#include "Radio.h"

using namespace std;

void main()
{
	//Normal::CarTestMain();
	//Inhertance::CarTestMain();
	//각 라디오 객체를 조작하도록 만들어보고, 각 객체의 설계방법중에 가장 적절한것이 무엇인지 자신의 생각을 말해보자.
	Inheritance::RadioMain();
	HasA_InClass::RadioMain();
	HasA_InRef::RadioMain();
}