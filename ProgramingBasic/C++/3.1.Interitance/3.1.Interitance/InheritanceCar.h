#pragma once
#include <iostream>

using namespace std;

namespace Inhertance
{
	class CVehicle
	{
	private:
		int m_nSpeed;
		int m_nGear;
		int m_nSeat;
	public:
		CVehicle(int seat = 1) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
		{
			cout << "CVehicle[" << this << "]" << endl;
			m_nGear = 1;
			m_nSpeed = 0;
			m_nSeat = seat;
		}
		//소멸자: 메모리가 해제될때 호출되는 함수.
		~CVehicle()
		{
			cout << "~CVehicle[" << this << "]" << endl;
		}
		void Accel()
		{
			m_nSpeed++;
		}
		void Break()
		{
			m_nSpeed--;
		}
		//직접적으로 속성을 변경하는 것은 아니나 꼭 필요하다.
		//이 함수가 없다는것은 계기판이 없는 차를 탄것과 다를것이 없다.
		void Display()
		{
			cout << "#### " << this << " ####" << endl;
			cout << "Gear:" << m_nGear << endl;
			cout << "Speed:" << m_nSpeed << endl;
			cout << "Seat:" << m_nSeat << endl;
		}
	};

	class CBike : public CVehicle
	{
	public:
		CBike(int seat = 1) { cout << "CBike[" << this << "]" << endl; }
		~CBike() { cout << "~CBike[" << this << "]" << endl; }
	};

	class CEnginner : public CVehicle
	{
	private:
		int m_nEngine;
	public:
		CEnginner(int seat = 2, int engine = 100) :CVehicle(seat) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
		{
			cout << "CEnginner[" << this << "]" << endl;
			m_nEngine = engine;
		}
		//소멸자: 메모리가 해제될때 호출되는 함수.
		~CEnginner()
		{
			cout << "~CEnginner[" << this << "]" << endl;
		}
	};
	//계층상속: 부모를 가진 클래스를 자식으로 상속받는 것.
	//다이아몬드 상속: 같은 부모를 가진 두 자식객체를 부모를 2개이상 상속받는것.(다른객체지향형언에서는 다중상속이 불가능하다)
	//다아이몬드 상속의 문제점: 같은 부모를 가지므로 부모부분이 두번생성된다.(즉, Vehicle의 멤버가 CBike,CEnginner각 각 생성 된다)
	class CAutoBike : public CBike, public CEnginner //자전거의 특징과 엔진을 가지므로 다음과 같이 다중상속을 한다.
	{
	public:
		CAutoBike(int seat = 2, int engine = 100) :CBike(seat),CEnginner(seat, engine) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
		{
			cout << "CAutoBike[" << this << "]" << endl;
		}
		//소멸자: 메모리가 해제될때 호출되는 함수.
		~CAutoBike()
		{
			cout << "~CAutoBike[" << this << "]" << endl;
		}
	};
	//class CAutoBike : public CVehicle
	//{
	//private:
	//	int m_nEngine;
	//public:
	//	CAutoBike(int seat = 2, int engine = 100):CVehicle(seat) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
	//	{
	//		cout << "CAutoBike[" << this << "]" << endl;
	//		m_nEngine = engine;
	//	}
	//	//소멸자: 메모리가 해제될때 호출되는 함수.
	//	~CAutoBike()
	//	{
	//		cout << "~CAutoBike[" << this << "]" << endl;
	//	}
	//};
	//멤버가 전혀 추가되지않는 클래스가 굳이 필요한가?
	//class CBus: public CAutoBike
	//{
	//public:
	//	CBus(int seat = 24, int engine = 5000) :CAutoBike(seat, engine) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
	//	{
	//		cout << "CBus[" << this << "]" << endl;
	//	}
	//	//소멸자: 메모리가 해제될때 호출되는 함수.
	//	~CBus()
	//	{
	//		cout << "~CBus[" << this << "]" << endl;
	//	}
	//};
	//계층상속
	class CTruck : public CEnginner
	{
	private:
		int m_nWeight = 0;
	public:
		CTruck(int m_nWeight = 1000, int engine = 3000) :CEnginner(m_nWeight, engine) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
		{
			cout << "CTruck[" << this << "]" << endl;
			m_nWeight = engine;
		}
		//소멸자: 메모리가 해제될때 호출되는 함수.
		~CTruck()
		{
			cout << "~CTruck[" << this << "]" << endl;
		}
	};

	void CarTestMain()
	{
		//CBike cBike;
		//CVehicle cBike; //탈것의 멤버를 그대로 가지므로 객체를 생성할때 이름을 지정하여 자전거로 만들수있다.
		//멤버는 같으므로 굳이 다른 클래스를 만들 필요가없다.
		//CEnginner cAutoBike(2,100);
		//CEnginner cBus(24,5000);
		//멤버변수가 추가되지않는 클래스를 굳이 많이 만들필요가 없다.
		CAutoBike cAutoBike;
		//CAutoBike cBus; //오토바이로 버스를 만들수있는가? -> 문법적으로 문제가 없으나 개념이 이상하다.
		//CBus cBus; //오토바이랑 특성이 같으므로 만들필요없음.
		//CTruck cTruck;
	}
}