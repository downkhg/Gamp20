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
	static int m_nCount; //자동차가 생산된 대수 //정적맴버변수의 선언
public:
	static int GetCount() { return m_nCount; } //정적맴버함수
	//매개변수로 값을 받고 내부에서 값을 변경한다?
	void SetGear(int nGear)
	{
		cout << "Input ";
		cin >> nGear;
		m_eGear = (E_GEAR)nGear;
	}
	//※잘못된 인터페이스의 설계
	//맴버를 입력받기위한 함수를 따로 만드는것은 상식적이지만,
	//세터가 내부에서 매개변수의 값을 바꾸는것은 의도하지않은 동작을 일으킬수있다.
	//그렇다고하지만, 실제로 이러한 함수를 내부에 클래스내부에 포함하는 것도 일반적이지는 않다.
	void InputGear()
	{
		int nGear;
		cout << "Input ";
		cin >> nGear;
		m_eGear = (E_GEAR)nGear;
	}
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
//private: //생성자가 private이라면 객체 생성이 불가능해진다. 그러므로 싱글톤이외에 거이 쓸일은 없다.
	//디폴트매개변수를 이용하여 기본생성자를 지정하지않아도 가능하게 만들수있다.
public:
	CCar(string color = "Gray", E_GEAR gear =E_GEAR::N, int speed = 0) //생성자를 이용하여, 클래스생성시에 초기값을 반드시 할당하도록 만들수있다.
	{
		m_nCount++;
		cout << "CCar[" << this << "/" << m_nCount << "]:" << color << endl;
		m_strColor = color;
		m_eGear = gear;
		m_nSpeed = speed;
	}
	//복사생성자: 객체가 초기화될때 다른객체에서 복사가되면 호출되는 함수
	CCar(CCar& car)
	{
		m_nCount++;
		//memcpy_s(this, sizeof(CCar), &car, sizeof(CCar)); //일부컴퓨터에서 문제가 발생하는 경우가 있음.
		this->m_nSpeed = car.m_nSpeed;
		this->m_strColor = car.m_strColor;
		this->m_eGear = car.m_eGear;
		cout << "CCar Copy[" << this << "/" << m_nCount << "]:" << m_strColor << endl;
	}
	//소멸자: 메모리가 해제될때 호출되는 함수.
	~CCar()
	{
		m_nCount--;
		cout << "~CCar[" << this << "/"<<m_nCount<<"]:" << m_strColor << endl;
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
		cout <<"#### "<< m_strColor<<" ####"<< endl;
		cout << "Gear:" << m_eGear << endl;
		cout << "Speed:" << m_nSpeed << endl;
	}
};

int CCar::m_nCount = 0; //정적맴버변수의 정의

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

	cout << "CarTestMain() End!" << endl;
}
//자동차를 구매하기
//1. 매장을 방문한다. 
//2. 시승을 한다
//3. 마음에 들면 계약서를 작성한다.
//4. 차가 생산한다.
//5. 생산된 차를 출고한다.
//6. 자차로 사용한다.
void BuyCarMain()
{
	string strInputColor;
	cout << "Color?:";
	cin >> strInputColor;
	cout << "Car Produuces!" << endl;
	CCar cCar(strInputColor);
	cout << "#### Shipping Car ####" << endl;
	int nCtrl = 0;
	do
	{
		cout << "Car Drive" << endl;
		cin >> nCtrl;
		switch (nCtrl)
		{
		case 1: 
			int nGear;
			cout << "Input Gear" << endl;
			cin >> nGear;
			cCar.SetGear((CCar::E_GEAR)nGear);
			break;
		case 2:
			cout << "Accelerate" << endl;
			cCar.Accel();
			break;
		case 3:
			cout << "break" << endl;
			cCar.Accel();
			break;
		default:
			nCtrl = -1;
			break;
		}
		cCar.Display();
	} 	while (nCtrl != -1);
	
}
//매개변수로 입력를 만들고 함수안에서 입력함수를 통해 값을 받는다.
//
void main()
{
	cout << "main() Start!" << endl;
	cout << "CarCount:" << CCar::GetCount() << endl;
	//CarTestMain();
	SwapTestMain();
	cout << "CarCount:" << CCar::GetCount() << endl;
	cout << "main() End!" << endl;
}