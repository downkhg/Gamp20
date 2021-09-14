#include <iostream>
#include <string>

using namespace std;
//�߻�ȭ: ������ ���� ��üȭ�ϱ� ���ؼ� �м��ϴ� ��.
//�Ӽ�: ����ɼ��ִ°�(����). ����:�Ӽ��� ��ȭ��Ű�� ��(����-�Լ�).
//����: �Ӽ�-���� ����-�ѱ�/����
//����: �Ӽ�-����,���ļ�,���� ����-���ļ�����,��������,�ѱ�/����
//������(����/����): �Ӽ� - �����, ������, û�ᵵ/ü��,���ݷ�, ���� - �Ա�, ���, ��� / ����,��ų 
//����ü�� ��Ȯ�ϰ� �߻�ȭ�ϱ� ��ƴ�. -> ������ �帣: ���� , ����

//�ڵ���: �Ӽ�-�ӵ�,����,��� ����-����,�극��ũ,����,���󺯰�?
class CCar//Ŭ����: ���赵
{
public:
	enum E_GEAR { P, R, N, D, ONE, TOW };

	string m_strColor;
	int m_nSpeed;
	E_GEAR m_eGear;
	//������: ��ü�� �����ɶ� ȣ��Ǵ� �Լ�
	CCar(string color, E_GEAR gear, int speed)
	{
		m_strColor = color;
		m_eGear = gear;
		m_nSpeed = speed;
	}

	void Accel()
	{
		m_nSpeed++;
	}
	void Break()
	{
		m_nSpeed--;
	}
	void SetGear(E_GEAR eGear)
	{
		m_eGear = eGear;
	}
	void SetColor(string color)
	{
		m_strColor = color;
	}
	void Display()
	{
		cout <<"#### "<< m_strColor<<" ####"<< endl;
		cout << "Gear:" << m_eGear << endl;
		cout << "Speed:" << m_nSpeed << endl;
	}
};

void CarTestMain()
{
	CCar cCar("Red",CCar::E_GEAR::N, 0);

	cCar.m_strColor = "Red";
	cCar.m_nSpeed = 0;
	cCar.m_eGear = CCar::E_GEAR::P;

	cCar.Accel();
	cCar.Display();
}

void main()
{
	CarTestMain();
}