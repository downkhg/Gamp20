#include <iostream>
#include <string>

using namespace std;
//추상화: 현실의 모델을 객체화하기 위해서 분석하는 것.
//속성: 변경될수있는것(변수). 동작:속성을 변화시키는 것(연산-함수).
//전구: 속성-전원 동작-켜기/끄기
//라디오: 속성-전원,주파수,음량 동작-주파수변경,음량조절,켜기/끄기
//강아지(육성/전투): 속성 - 배고픔, 애정도, 청결도/체력,공격력, 동작 - 먹기, 놀기, 목욕 / 공격,스킬 
//생명체는 명확하게 추상화하기 어렵다. -> 게임의 장르: 육성 , 전투

//자동차: 속성-속도,색상,기어 동작-엑셀,브레이크,기어변경,색상변경?
class CCar//클래스: 설계도
{
public:
	enum E_GEAR { P, R, N, D, ONE, TOW };

	string m_strColor;
	int m_nSpeed;
	E_GEAR m_eGear;
	//생성자: 객체가 생성될때 호출되는 함수
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