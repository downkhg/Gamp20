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
private:
	string m_strColor;
	int m_nSpeed;
	E_GEAR m_eGear;
public:
	//Getter: 어떤 멤버변수를 가져오는 함수. 
	string GetColor() { return m_strColor; }; //색상을 변경하면 범죄행위다 기본적으로는 관찰만 가능하다.
	int GetSpeed() { return m_nSpeed; }  //물리법칙에 의해서 속도를 변경하는 방법은 가속/감속 말고는 존제하지않으므로, 변경을 못하게한다.
	//Setter: 어떤 멤버변수를 설정하는 함수.
	void SetGear(E_GEAR eGear){ m_eGear = eGear; }//기어는 스택으로 조절가능하다.
	void SetColor(string color){ m_strColor = color; }//색상은 내가 허용하면 변경가능하다.
	//생성자: 객체가 생성될때 호출되는 함수
	//CCar() //기본생성자 - 매개변수가 없는 생성자:객체를 생성할때 매개변수를 지정하지않아도 생성되게 하려면 필요하다.
	//{
	//	m_strColor = "Gray";
	//	m_eGear = E_GEAR::N;
	//	m_nSpeed = 0;
	//}
	//디폴트매개변수를 이용하여 기본생성자를 지정하지않아도 가능하게 만들수있다.
	CCar(string color = "Gray", E_GEAR gear =E_GEAR::N, int speed = 0) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
	{
		cout << "CCar[" << this << "]:" << color << endl;
		m_strColor = color;
		m_eGear = gear;
		m_nSpeed = speed;
	}
	//소멸자: 메모리가 해제될때 호출되는 함수.
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

	void Display()
	{
		cout <<"#### "<< m_strColor<<" ####"<< endl;
		cout << "Gear:" << m_eGear << endl;
		cout << "Speed:" << m_nSpeed << endl;
	}
};

void SwapCarVal(CCar cCarA, CCar cCarB)
{
	CCar temp = cCarA;
	cCarA = cCarB;
	cCarB = temp;
}

void SwapCarRef(CCar& cCarA, CCar& cCarB)
{
	CCar temp = cCarA;
	cCarA = cCarB;
	cCarB = temp;
}

void CarTestMain()
{
	cout << "CarTestMain() Start!" << endl;
	//클래스객체를 메모리할당
	CCar cCar("Red", CCar::E_GEAR::N, 0);
	CCar arrCar[3];
	CCar* pCar = NULL; //포인터를 생성시 객체는 없다.
	cout << "cCar:" << &cCar << endl;

	pCar = new CCar("blue"); //객체를 동적할당하고 객체의 주소값을 포인터에 저장한다.
	delete pCar; //동적할당된 객체의 메모리를 해제한다.
	
	//사용자의 승인없이 값이 변경되는것은 법적으로 금지되어있다.
	//이를 나타나게 하려면, private멤버로 변경하면된다.
	/*cCar.m_strColor = "Red";
	cCar.m_nSpeed = 0;
	cCar.m_eGear = CCar::E_GEAR::P;*/
	cCar.Accel();
	cCar.Display();

	CCar cCarB("green");
	SwapCarVal(cCar, cCarB);
	cCar.Display();
	cCarB.Display();
	SwapCarRef(cCar, cCarB);
	cCar.Display();
	cCarB.Display();
	cout << "CarTestMain() End!" << endl;
}

void main()
{
	cout << "main() Start!" << endl;
	CarTestMain();
	cout << "main() End!" << endl;
}