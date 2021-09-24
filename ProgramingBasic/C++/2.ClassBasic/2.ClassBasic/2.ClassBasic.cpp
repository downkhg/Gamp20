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
private:
	string m_strColor;
	int m_nSpeed;
	E_GEAR m_eGear;
public:
	//Getter: � ��������� �������� �Լ�. 
	string GetColor() { return m_strColor; }; //������ �����ϸ� ���������� �⺻�����δ� ������ �����ϴ�.
	int GetSpeed() { return m_nSpeed; }  //������Ģ�� ���ؼ� �ӵ��� �����ϴ� ����� ����/���� ����� �������������Ƿ�, ������ ���ϰ��Ѵ�.
	//Setter: � ��������� �����ϴ� �Լ�.
	void SetGear(E_GEAR eGear){ m_eGear = eGear; }//���� �������� ���������ϴ�.
	void SetColor(string color){ m_strColor = color; }//������ ���� ����ϸ� ���氡���ϴ�.
	//������: ��ü�� �����ɶ� ȣ��Ǵ� �Լ�
	//CCar() //�⺻������ - �Ű������� ���� ������:��ü�� �����Ҷ� �Ű������� ���������ʾƵ� �����ǰ� �Ϸ��� �ʿ��ϴ�.
	//{
	//	m_strColor = "Gray";
	//	m_eGear = E_GEAR::N;
	//	m_nSpeed = 0;
	//}
	//����Ʈ�Ű������� �̿��Ͽ� �⺻�����ڸ� ���������ʾƵ� �����ϰ� ������ִ�.
	CCar(string color = "Gray", E_GEAR gear =E_GEAR::N, int speed = 0) //�����ڸ� �̿��Ͽ�, Ŭ���������ÿ� �ʱⰪ�� �ݵ�� �Ҵ��ϵ��� ������ִ�.
	{
		cout << "CCar[" << this << "]:" << color << endl;
		m_strColor = color;
		m_eGear = gear;
		m_nSpeed = speed;
	}
	//���������: ��ü�� �ʱ�ȭ�ɶ� �ٸ���ü���� ���簡�Ǹ� ȣ��Ǵ� �Լ�
	CCar(CCar& car)
	{
		//memcpy_s(this, sizeof(CCar), &car, sizeof(CCar)); //�Ϻ���ǻ�Ϳ��� ������ �߻��ϴ� ��찡 ����.
		this->m_nSpeed = car.m_nSpeed;
		this->m_strColor = car.m_strColor;
		this->m_eGear = car.m_eGear;
		cout << "CCar Copy[" << this << "]:" << m_strColor << endl;
	}
	//�Ҹ���: �޸𸮰� �����ɶ� ȣ��Ǵ� �Լ�.
	~CCar()
	{
		cout << "~CCar[" << this << "]:" << m_strColor << endl;
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
		cout <<"#### "<< m_strColor<<" ####"<< endl;
		cout << "Gear:" << m_eGear << endl;
		cout << "Speed:" << m_nSpeed << endl;
	}
};
void SwapCarVal(CCar cCarA, CCar cCarB)
{
	cout << "SwapCarVal" << endl;
	CCar temp = cCarA;
	cCarA = cCarB;
	cCarB = temp;
}
void SwapCarRef(CCar& cCarA, CCar& cCarB)
{
	cout << "SwapCarRef" << endl;
	CCar temp = cCarA;
	cCarA = cCarB;
	cCarB = temp;
}
void SwapTestMain()
{
	CCar cCarA("yellow");
	CCar cCarB("green");
	cCarA.Display();
	cCarB.Display();
	SwapCarVal(cCarA, cCarB);
	cCarA.Display();
	cCarB.Display();
	SwapCarRef(cCarA, cCarB);
	cCarA.Display();
	cCarB.Display();
}

void CarTestMain()
{
	cout << "CarTestMain() Start!" << endl;
	//Ŭ������ü�� �޸��Ҵ�
	CCar cCar("Red", CCar::E_GEAR::N, 0);
	CCar arrCar[3];
	CCar* pCar = NULL; //�����͸� ������ ��ü�� ����.
	cout << "cCar:" << &cCar << endl;

	pCar = new CCar("blue"); //��ü�� �����Ҵ��ϰ� ��ü�� �ּҰ��� �����Ϳ� �����Ѵ�.
	delete pCar; //�����Ҵ�� ��ü�� �޸𸮸� �����Ѵ�.
	
	//������� ���ξ��� ���� ����Ǵ°��� �������� �����Ǿ��ִ�.
	//�̸� ��Ÿ���� �Ϸ���, private����� �����ϸ�ȴ�.
	/*cCar.m_strColor = "Red";
	cCar.m_nSpeed = 0;
	cCar.m_eGear = CCar::E_GEAR::P;*/
	cCar.Accel();
	cCar.Display();

	cout << "CarTestMain() End!" << endl;
}

void main()
{
	cout << "main() Start!" << endl;
	//CarTestMain();
	SwapTestMain();
	cout << "main() End!" << endl;
}