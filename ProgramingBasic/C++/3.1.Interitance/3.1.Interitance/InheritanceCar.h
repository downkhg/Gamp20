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
		CBike() { cout << "CBike[" << this << "]" << endl; }
		~CBike() { cout << "~CBike[" << this << "]" << endl; }
	};

	class CAutoBike : public CVehicle
	{
	private:
		int m_nEngine;
	public:
		CAutoBike(int seat = 2, int engine = 100):CVehicle(seat) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
		{
			cout << "CAutoBike[" << this << "]" << endl;
			m_nEngine = engine;
		}
		//소멸자: 메모리가 해제될때 호출되는 함수.
		~CAutoBike()
		{
			cout << "~CAutoBike[" << this << "]" << endl;
		}
	};

	class CBus: public CAutoBike
	{
	private:
		int m_nEngine;
	public:
		CBus(int seat = 24, int engine = 5000) :CAutoBike(seat, engine) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
		{
			cout << "CBus[" << this << "]" << endl;
			m_nEngine = engine;
		}
		//소멸자: 메모리가 해제될때 호출되는 함수.
		~CBus()
		{
			cout << "~CBus[" << this << "]" << endl;
		}
	};

	class CTruck : public CBus
	{
	private:
		int m_nWeight = 0;
	public:
		CTruck(int m_nWeight = 1000, int engine = 3000) :CBus(m_nWeight, engine) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
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
		CBike cBike;
		CAutoBike cAutoBike;
		CBus cBus;
		CTruck cTruck;
	}
}