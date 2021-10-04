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
		CVehicle(int seat = 1) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CVehicle[" << this << "]" << endl;
			m_nGear = 1;
			m_nSpeed = 0;
			m_nSeat = seat;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
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
		//���������� �Ӽ��� �����ϴ� ���� �ƴϳ� �� �ʿ��ϴ�.
		//�� �Լ��� ���ٴ°��� ������� ���� ���� ź�Ͱ� �ٸ����� ����.
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
		CAutoBike(int seat = 2, int engine = 100):CVehicle(seat) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CAutoBike[" << this << "]" << endl;
			m_nEngine = engine;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
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
		CBus(int seat = 24, int engine = 5000) :CAutoBike(seat, engine) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CBus[" << this << "]" << endl;
			m_nEngine = engine;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
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
		CTruck(int m_nWeight = 1000, int engine = 3000) :CBus(m_nWeight, engine) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CTruck[" << this << "]" << endl;
			m_nWeight = engine;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
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