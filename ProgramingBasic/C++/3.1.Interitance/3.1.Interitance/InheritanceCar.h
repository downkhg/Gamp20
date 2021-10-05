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
		CBike(int seat = 1) { cout << "CBike[" << this << "]" << endl; }
		~CBike() { cout << "~CBike[" << this << "]" << endl; }
	};

	class CEnginner : public CVehicle
	{
	private:
		int m_nEngine;
	public:
		CEnginner(int seat = 2, int engine = 100) :CVehicle(seat) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CEnginner[" << this << "]" << endl;
			m_nEngine = engine;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
		~CEnginner()
		{
			cout << "~CEnginner[" << this << "]" << endl;
		}
	};
	//�������: �θ� ���� Ŭ������ �ڽ����� ��ӹ޴� ��.
	//���̾Ƹ�� ���: ���� �θ� ���� �� �ڽİ�ü�� �θ� 2���̻� ��ӹ޴°�.(�ٸ���ü�������𿡼��� ���߻���� �Ұ����ϴ�)
	//�پ��̸�� ����� ������: ���� �θ� �����Ƿ� �θ�κ��� �ι������ȴ�.(��, Vehicle�� ����� CBike,CEnginner�� �� ���� �ȴ�)
	class CAutoBike : public CBike, public CEnginner //�������� Ư¡�� ������ �����Ƿ� ������ ���� ���߻���� �Ѵ�.
	{
	public:
		CAutoBike(int seat = 2, int engine = 100) :CBike(seat),CEnginner(seat, engine) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
		{
			cout << "CAutoBike[" << this << "]" << endl;
		}
		//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
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
	//	CAutoBike(int seat = 2, int engine = 100):CVehicle(seat) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
	//	{
	//		cout << "CAutoBike[" << this << "]" << endl;
	//		m_nEngine = engine;
	//	}
	//	//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
	//	~CAutoBike()
	//	{
	//		cout << "~CAutoBike[" << this << "]" << endl;
	//	}
	//};
	//����� ���� �߰������ʴ� Ŭ������ ���� �ʿ��Ѱ�?
	//class CBus: public CAutoBike
	//{
	//public:
	//	CBus(int seat = 24, int engine = 5000) :CAutoBike(seat, engine) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
	//	{
	//		cout << "CBus[" << this << "]" << endl;
	//	}
	//	//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
	//	~CBus()
	//	{
	//		cout << "~CBus[" << this << "]" << endl;
	//	}
	//};
	//�������
	class CTruck : public CEnginner
	{
	private:
		int m_nWeight = 0;
	public:
		CTruck(int m_nWeight = 1000, int engine = 3000) :CEnginner(m_nWeight, engine) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
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
		//CBike cBike;
		//CVehicle cBike; //Ż���� ����� �״�� �����Ƿ� ��ü�� �����Ҷ� �̸��� �����Ͽ� �����ŷ� ������ִ�.
		//����� �����Ƿ� ���� �ٸ� Ŭ������ ���� �ʿ䰡����.
		//CEnginner cAutoBike(2,100);
		//CEnginner cBus(24,5000);
		//��������� �߰������ʴ� Ŭ������ ���� ���� �����ʿ䰡 ����.
		CAutoBike cAutoBike;
		//CAutoBike cBus; //������̷� ������ ������ִ°�? -> ���������� ������ ������ ������ �̻��ϴ�.
		//CBus cBus; //������̶� Ư���� �����Ƿ� �����ʿ����.
		//CTruck cTruck;
	}
}