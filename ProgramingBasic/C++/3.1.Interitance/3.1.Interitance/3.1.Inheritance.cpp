#include <iostream>
#include "Car.h"
#include "InheritanceCar.h"
#include "Radio.h"

using namespace std;

void main()
{
	//Normal::CarTestMain();
	//Inhertance::CarTestMain();
	//�� ���� ��ü�� �����ϵ��� ������, �� ��ü�� �������߿� ���� �����Ѱ��� �������� �ڽ��� ������ ���غ���.
	Inheritance::RadioMain();
	HasA_InClass::RadioMain();
	HasA_InRef::RadioMain();
}