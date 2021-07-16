#include <stdio.h>//표준입출력
#define PI 3.141592
//전처리기: 컴파일전에 코드를 처리해주는 것.
//원의 넓이를 구하는 프로그램만들기(단, 원의 넓이는 입력을 받고, 구한 원의넓이를 출력하라)
//반지름*반지름*3.14 = 원의 넓이 //정수:int 실수:float 변수:데이터를 담는 것
//데이터(재료): 반지름, 3.14 = Pi
//알고리즘(레시피): 반지름*반지름*3.14 = 원의 넓이, 구한 원의 넓이를 출력하라.
void CircleAreaMain()
{
	//1.변수 반지름을 만들고 값을 저장한다.
	//2.변수 파이를 만들고 값을 저장한다.
	//3.원의 넓이를 반지름*반지름*3.14을 이용하여 구한다.
	//4.원의 넓이를 출력한다.
	float radius = 1;//F9:중단점설정
	const float pi = 3.14;//const: 컴파일러야 내가 실수하면 니가 알려줘
	
	//float area = radius * radius * pi;
	float area = radius * radius * PI; //전처리기에서 값을 바꿔준다.
	printf("Area:%f\n",area);
}
//변수 x와 각 데이터형의 크기를 출력하는 프로그램
void SizeMain()
{
	int x;
	printf("x:%d\n",sizeof(x));
	printf("char:%d\n", sizeof(char));
	printf("int:%d\n", sizeof(int));
	printf("float:%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));
}
//아스키(ASCII)코드: 미국표준코드, 영어나 특수문자만 나타낼수있음. 0~255까지의 숫자에 문자가 대치됨.
void CharMain()
{
	int nDataA = 'A';
	char cDataA = 'A';

	printf("nDataA:%c,%d\n", nDataA, nDataA);
	printf("cDataA:%c,%d\n", cDataA, cDataA);
}

void LightSpeedMain()
{

}

void main()
{
	//주석: 컴파일러가 분석하지않는 문장.
	//ctrl+f5: 컴파일(빌드)+디버그없이 실행하기
	//printf("Hello Wolrd!\n");//\n:줄바꿈문자.
	//printf("khg");//;(세미콜론) 문장끝을 나타내는 기호
	//CircleAreaMain();
	//SizeMain();
	CharMain();
}