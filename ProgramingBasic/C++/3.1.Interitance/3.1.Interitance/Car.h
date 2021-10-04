#pragma once
#include <iostream>

using namespace std;

namespace Normal
{
	class CBike
	{
	private:
		int m_nSpeed;
		int m_nGear;
		int m_nSeat;
	public:
		CBike(int seat = 1) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CBike[" << this << "]"<< endl;
			m_nGear = 1;
			m_nSpeed = 0;
			m_nSeat = seat;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
		~CBike()
		{
			cout << "~CBike[" << this << "]" << endl;
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

	class CAutoBike
	{
	private:
		int m_nSpeed;
		int m_nGear;
		int m_nSeat;
		int m_nEngine;
	public:
		CAutoBike(int seat = 2, int engine = 100) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CAutoBike[" << this << "]" << endl;
			m_nGear = 1;
			m_nSpeed = 0;
			m_nSeat = seat;
			m_nEngine = engine;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
		~CAutoBike()
		{
			cout << "~CAutoBike[" << this << "]" << endl;
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

	class CBus
	{
	private:
		int m_nSpeed;
		int m_nGear;
		int m_nSeat;
		int m_nEngine;
	public:
		CBus(int seat = 24, int engine = 5000) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CBus[" << this << "]" << endl;
			m_nGear = 1;
			m_nSpeed = 0;
			m_nSeat = seat;
			m_nEngine = engine;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
		~CBus()
		{
			cout << "~CBus[" << this << "]" << endl;
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

	class CTruck
	{
	private:
		int m_nSpeed;
		int m_nGear;
		int m_nSeat;
		int m_nEngine;
		int m_nWeight;
	public:
		CTruck(int seat = 2, int engine = 3000, int weight = 1000) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CTruck[" << this << "]" << endl;
			m_nGear = 1;
			m_nSpeed = 0;
			m_nSeat = seat;
			m_nEngine = engine;
			m_nWeight = weight;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
		~CTruck()
		{
			cout << "~CTruck[" << this << "]" << endl;
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

	void CarTestMain()
	{
		CBike cBike;
		CAutoBike cAutoBike;
		CBus cBus;
		CTruck cTruck;
	}
}