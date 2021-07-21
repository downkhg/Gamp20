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
	int nDataA = '1';
	char cDataA = 1;

	printf("nDataA:%c,%d\n", nDataA, nDataA);
	printf("cDataA:%c,%d\n", cDataA, cDataA);
}
//태양과 지구사이의 거리가 주어졌을때, 빛이 지구에 도달하는 시간(초)(분)
//빛속도: 30만 km/s
//태양과 지구사이거리: 14960만 km
// _
// ________________________________
//데이터:빛의속도,태양과지구사이거리,시간(초) -> 변수: int
//알고리즘: 태양과지구사이거리/빛의속도 = 시간
//나누기를 할때는 나누어 떨어지지 않을수있으므로 실수를 사용하는 것이 좋다.
void LightSpeedMain()
{
	int nLighitSpeed = 30;
	int nDistance = 14960;
	int nSec = 14960/30;
	printf("%d s\n",nSec);
	printf("%f m\n", (float)nSec/60.0f);//타입변환(캐스팅)
	printf("%d m %ds\n",nSec/60, nSec%60);
	int nSec2 = nSec / 60;
	printf("%d m %ds\n", nSec / 60, nSec - (nSec2 * 60));
}

void OpMain()
{
	int nDataA = 10; //10
	int nDataB = 20; //20

	int nDataC = nDataA++; //10=10 -> 11
	int nDataD = --nDataB;

	printf("A/C:%d/%d\n",nDataA,nDataC);
	printf("B/D:%d/%d\n", nDataB, nDataD);
}

void BitmaskMain()
{
	unsigned int  color = 0x00385555;
	unsigned int result;
	printf("PixelColor:%#08x\n", color);
	result = color & 0x00ff00ff;
	printf("MaskColor: %#08x\n", result);
	result = result >> 16;
	printf("result>>16:%#08x\n", result);
}
//점수를 입력받아 학점을 계산하는 프로그램.
//(단, 90점이상 A, 80이상 90미만 B, 70이상 80미만 C, 60이상 70미만 D, 60이하 F)
//데이터: 점수, 학점
//알고리즘:  90점이상 A, 80이상 90미만 B, 70이상 80미만 C, 60이상 70미만 D, 60이하 F
void ScoreCheckMain()
{
	int nSocore;
	char cGrade;
	printf("Score:");
	scanf("%d", &nSocore);//100

	//if문을 활용하면 모든조건을 비교해야하지만, if els문은 연산량이 적다.
	/*
	if (nSocore >= 90) //90 T
	{
		cGrade = 'A';
	}
	if (nSocore >= 80 && nSocore < 90) //90 F
	{
		cGrade = 'B';
	}
	if (nSocore >= 70 && nSocore < 80)//90 F
	{
		cGrade = 'C';
	}
	if (nSocore >= 60 && nSocore < 70)//90 F
	{
		cGrade = 'D';
	}
	if (nSocore < 60)//90 F
	{
		cGrade = 'F';
	}*/
	if (nSocore >= 90)//100 >= 90 => T
	{
		cGrade = 'A';
	}
	else if (nSocore >= 80)
	{
		cGrade = 'B';
	}
	else if (nSocore >= 70)
	{
		cGrade = 'C';
	}
	else if (nSocore >= 60)
	{
		cGrade = 'D';
	}
	else if (nSocore < 60)
	{
		cGrade = 'F';
	}
	printf("Grade:%c/%d\n",cGrade,nSocore);
}
//계산할 변수와 연산은 입력을 통해 계산 방법을 바꿀수있는 계산기(사칙연산)
//Input: 1+1
//output: 1+1=2
//데이터: 계산값2개,결과값,연산(정수,문자),
//알고리즘: 연산된 값에 따라 두입력값을 계산한다.
void CalMain()
{
	int nInputA;
	int nInputB;
	int nResult;
	char cInputOp;
	printf("ex)1+1\n");
	scanf("%d%c%d",&nInputA,&cInputOp,&nInputB);
	if (cInputOp == '+')
	{
		nResult = nInputA + nInputB;
	}
	else if (cInputOp == '-')
	{
		nResult = nInputA - nInputB;
	}
	else if (cInputOp == '*')
	{
		nResult = nInputA * nInputB;
	}
	else if (cInputOp == '/')
	{
		nResult = nInputA / nInputB;
	}
	else
		printf("!?!?!?!?!?!\n");
	//switch (cInputOp)//+
	//{
	//case '+':
	//	nResult = nInputA + nInputB;// 2=1+1
	//	break;
	//case '-':
	//	nResult = nInputA - nInputB;
	//	break;
	//case '*':
	//	nResult = nInputA * nInputB;
	//	break;
	//case '/':
	//	nResult = nInputA / nInputB;
	//	break;
	//default:
	//	printf("!?!?!?!?!?!\n");
	//	break;
	//}
	printf("%d%c%d = %d\n", nInputA, cInputOp, nInputB, nResult);
}

void main()
{
	//주석: 컴파일러가 분석하지않는 문장.
	//ctrl+f5: 컴파일(빌드)+디버그없이 실행하기
	//printf("Hello Wolrd!\n");//\n:줄바꿈문자.
	//printf("khg");//;(세미콜론) 문장끝을 나타내는 기호
	//CircleAreaMain();
	//SizeMain();
	//CharMain();
	//LightSpeedMain();
	//BitmaskMain();
	//OpMain();
	ScoreCheckMain();
}