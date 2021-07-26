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
//마일을 메터로 변경하여 0~2마일까지 출력하는 프로그램
//1마일은 1609미터다. 
//데이터: 마일,미터
//알고리즘: 0~2마일까지 출력
//while문이용시
//1.반복문과 상관없이 코드를 반복한다.
//2.반복문에 공통적인 규칙을 찾아 무한루프를 만든다.
//3.무한루프에 적절한 위치에서 탈출조건에 break문을 넣는다.
//4.무한루프의 조건으로 탈출조건의 반대조건을 넣는다.
void MailToMetaMain()
{
	int nMail;//?
	int nMeter;//?
	nMail = 0; //0
	//while (true)
	while(nMail <= 2)
	{
		// 0 = 0 * 1609 // 1609= 1*1609 // 3218=2*1609 //4827=3*1609
		nMeter = nMail * 1609;
		printf("Mail to Metter:%d -> %d\n", nMail, nMeter);//0,0 //1,1609 //2, 3218// 3, 4827
		//0>2->F //1>2->F //2>2->F //3>2->T
		//if (nMail > 2) break;
		nMail++;//0++ = 1 //1++ = 2 //2++ = 3
	}
	//for문은 특별한 조건없이 횟수가 반복될때 사용된다.
	for (nMail = 0; nMail < 3; nMail++)
	{
		nMeter = nMail * 1609;
		printf("Mail to Metter:%d -> %d\n", nMeter, nMeter);
	}
	/*nMail = 1;
	nMeter = nMail * 1609;
	printf("Mail to Metter:%d -> %d\n", nMeter, nMeter);

	nMail = 2;
	nMeter = nMail * 1609;
	printf("Mail to Metter:%d -> %d\n", nMeter, nMeter);*/
}
//박테리아가 두배씩 늘어날때 160마리 이상될때는 몇시간 후인가?
void BateriaMain()
{
	int nBateria = 10; //10
	int nTime = 0; //0

	//while (true)
	while(nBateria < 160)
	{
		nBateria = nBateria * 2;//20
		nTime++;
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		//if (nBateria >= 160) break;
	}

	//nBateria = nBateria * 2;//20
	//nTime = 1;

	//nBateria = nBateria * 2;//40
	//nTime = 2;

	//nBateria = nBateria * 2;//80
	//nTime = 3;

	//nBateria = nBateria * 2;//160
	//nTime = 4;

	printf("Time:%d\n", nTime);
}

//종이를 접으면 (면적)이 (1/2로 줄어)들때,
//(종이면적이 1/10이하)로 줄어들려면, (몇번접)아야하는가?
//데이터: 종이의면적,접은횟수
//알고리즘: 종이를 접어서 면적이 10%남으려면 몇번 접어야하는가?
void PaperAreaMain()
{
	float fPaperArea = 100; //100
	float fMinPaperArea = fPaperArea * 0.1;
	int nCount = 0; //0

	while (true)
	{
		fPaperArea = fPaperArea * 0.5; //50 = 100*0.5 //25 = 50 * 0.5 
		nCount++;//1 
		printf("PaperArea:%f\n", fPaperArea, nCount);//50,1 

		if (fPaperArea <= fMinPaperArea) break;  //50, 5 //25, 2.5
	}
	
}

//반감기: 방사능물질의양이 1/2가 되는 시간
//방사능 물질의 양이 2000년이 지난후 물질의 양은?
//반감기:400년
//방사능물질의양: 100
//데이터: 반감기, 방사능물질의양, 지난햇수 
//알고리즘: 남은 물질의양 = 물질양이 2000년후에는 어떻게되는가?
void HalfLifeForMain()
{
	int nHalfLife = 400;
	float fQuantity = 100;
	int nYear = 0; 
	//for문이용할때는 흐름보다, 반복하는 조건과 값을 보고 사용하는 것이 좋다. -> 적절하지않음.
	                //1.0 <= 2000 -> T //400
					//2.400 <= 2000 -> T //800
					//3.800 <= 2000 -> T //1200
					//4.1200 <= 2000 -> T //1600
					//5.1600 <= 2000 -> T //2000
					//6.2000 <= 2000 -> T //2400
					//7.2400 <= 2000 -> F
	for (nYear = 0; nYear <= 2000; nYear += 400)
	{
		fQuantity = fQuantity * 0.5f;//1.50=100*0.5f //2.50*0.5f = 25 //3.25*0.5f = 12.5 //4.12.5*0.5 = 6.25 //5.6.25*0.5f=3.125  //6. 1.5625 = 3.125 * 0.5 
		printf("Quantity:%f, Year:%d, HalfLife:%d\n", fQuantity, nYear, nHalfLife);
	}

	printf("Quantity:%f\n", fQuantity);
}

/* 다음모양을 출력하라.
해당모양의 이름의 함수안에 조건만 변경하여 해당모양이 출력되도록만들기
Full    Rect   Window Stair
y01234x
0#####  #####  #####  #
1#####  #   #  # # #  ##
2#####  #   #  #####  ###
3#####  #   #  # # #  ####
4#####  #####  #####  ##### */
//1.규칙을 찾는다.
//Rect(y,x) (1,1)(1,2)(1,3) (2,1)(2,2)(2,3) (3,1)(3,2)(3,3) 1~3
//Window  (1,1)(1,3) (3,1)(3,3) -> 홀수
//Stair '#' (0,0) (1,0)(1,1) (2,0)(2,1)(2,2) 
//		    (3,0)(3,1)(3,2)(3,3) (4,0)(4,1)(4,2)(4,3)
//2.규칙대로 조건을 모두 준다.
//
//3.규칙에서 줄일만한 부분이 없는지 찾는다.
//※Stair는 (조건문없이가능) -> y가 증가할때마다 x의 값이 증가한다.
void RectMain()
{
	for (int y = 0; y < 5; y++) //(?,0) //(?,1) //(?,2)//(?,3)//(0,4)
	{
		//(0,0),(1,0),(2,0),(3,0),(4,0)\n
		//(0,1),(1,1),(2,1),(3,1),(4,1)\n
		//(0,2),(1,2),(2,2),(3,2),(4,2)\n
		//(0,3),(1,3),(2,3),(3,3),(4,3)\n
		//(0,4),(1,4),(2,4),(3,4),(4,4)\n
		for (int x = 0; x < 5; x++)
		{
			printf("#");
		}
		printf("\n");
	}
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
	//ScoreCheckMain();
	//MailToMetaMain();
	//BateriaMain()
	//PaperAreaMain();
	//HalfLifeForMain();
	RectMain();
}