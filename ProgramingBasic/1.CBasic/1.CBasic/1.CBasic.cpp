#include <stdio.h>//ǥ�������
#define PI 3.141592
//��ó����: ���������� �ڵ带 ó�����ִ� ��.
//���� ���̸� ���ϴ� ���α׷������(��, ���� ���̴� �Է��� �ް�, ���� ���ǳ��̸� ����϶�)
//������*������*3.14 = ���� ���� //����:int �Ǽ�:float ����:�����͸� ��� ��
//������(���): ������, 3.14 = Pi
//�˰���(������): ������*������*3.14 = ���� ����, ���� ���� ���̸� ����϶�.
void CircleAreaMain()
{
	//1.���� �������� ����� ���� �����Ѵ�.
	//2.���� ���̸� ����� ���� �����Ѵ�.
	//3.���� ���̸� ������*������*3.14�� �̿��Ͽ� ���Ѵ�.
	//4.���� ���̸� ����Ѵ�.
	float radius = 1;//F9:�ߴ�������
	const float pi = 3.14;//const: �����Ϸ��� ���� �Ǽ��ϸ� �ϰ� �˷���
	
	//float area = radius * radius * pi;
	float area = radius * radius * PI; //��ó���⿡�� ���� �ٲ��ش�.
	printf("Area:%f\n",area);
}
//���� x�� �� ���������� ũ�⸦ ����ϴ� ���α׷�
void SizeMain()
{
	int x;
	printf("x:%d\n",sizeof(x));
	printf("char:%d\n", sizeof(char));
	printf("int:%d\n", sizeof(int));
	printf("float:%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));
}
//�ƽ�Ű(ASCII)�ڵ�: �̱�ǥ���ڵ�, ��� Ư�����ڸ� ��Ÿ��������. 0~255������ ���ڿ� ���ڰ� ��ġ��.
void CharMain()
{
	int nDataA = '1';
	char cDataA = 1;

	printf("nDataA:%c,%d\n", nDataA, nDataA);
	printf("cDataA:%c,%d\n", cDataA, cDataA);
}
//�¾�� ���������� �Ÿ��� �־�������, ���� ������ �����ϴ� �ð�(��)(��)
//���ӵ�: 30�� km/s
//�¾�� �������̰Ÿ�: 14960�� km
// _
// ________________________________
//������:���Ǽӵ�,�¾���������̰Ÿ�,�ð�(��) -> ����: int
//�˰���: �¾���������̰Ÿ�/���Ǽӵ� = �ð�
//�����⸦ �Ҷ��� ������ �������� �����������Ƿ� �Ǽ��� ����ϴ� ���� ����.
void LightSpeedMain()
{
	int nLighitSpeed = 30;
	int nDistance = 14960;
	int nSec = 14960/30;
	printf("%d s\n",nSec);
	printf("%f m\n", (float)nSec/60.0f);//Ÿ�Ժ�ȯ(ĳ����)
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
//������ �Է¹޾� ������ ����ϴ� ���α׷�.
//(��, 90���̻� A, 80�̻� 90�̸� B, 70�̻� 80�̸� C, 60�̻� 70�̸� D, 60���� F)
//������: ����, ����
//�˰���:  90���̻� A, 80�̻� 90�̸� B, 70�̻� 80�̸� C, 60�̻� 70�̸� D, 60���� F
void ScoreCheckMain()
{
	int nSocore;
	char cGrade;
	printf("Score:");
	scanf("%d", &nSocore);//100

	//if���� Ȱ���ϸ� ��������� ���ؾ�������, if els���� ���귮�� ����.
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
//����� ������ ������ �Է��� ���� ��� ����� �ٲܼ��ִ� ����(��Ģ����)
//Input: 1+1
//output: 1+1=2
//������: ��갪2��,�����,����(����,����),
//�˰���: ����� ���� ���� ���Է°��� ����Ѵ�.
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
//������ ���ͷ� �����Ͽ� 0~2���ϱ��� ����ϴ� ���α׷�
//1������ 1609���ʹ�. 
//������: ����,����
//�˰���: 0~2���ϱ��� ���
//while���̿��
//1.�ݺ����� ������� �ڵ带 �ݺ��Ѵ�.
//2.�ݺ����� �������� ��Ģ�� ã�� ���ѷ����� �����.
//3.���ѷ����� ������ ��ġ���� Ż�����ǿ� break���� �ִ´�.
//4.���ѷ����� �������� Ż�������� �ݴ������� �ִ´�.
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
	//for���� Ư���� ���Ǿ��� Ƚ���� �ݺ��ɶ� ���ȴ�.
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
//���׸��ư� �ι辿 �þ�� 160���� �̻�ɶ��� ��ð� ���ΰ�?
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

//���̸� ������ (����)�� (1/2�� �پ�)�鶧,
//(���̸����� 1/10����)�� �پ�����, (�����)�ƾ��ϴ°�?
//������: �����Ǹ���,����Ƚ��
//�˰���: ���̸� ��� ������ 10%�������� ��� ������ϴ°�?
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

//�ݰ���: ���ɹ����Ǿ��� 1/2�� �Ǵ� �ð�
//���� ������ ���� 2000���� ������ ������ ����?
//�ݰ���:400��
//���ɹ����Ǿ�: 100
//������: �ݰ���, ���ɹ����Ǿ�, �����޼� 
//�˰���: ���� �����Ǿ� = �������� 2000���Ŀ��� ��ԵǴ°�?
void HalfLifeForMain()
{
	int nHalfLife = 400;
	float fQuantity = 100;
	int nYear = 0; 
	//for���̿��Ҷ��� �帧����, �ݺ��ϴ� ���ǰ� ���� ���� ����ϴ� ���� ����. -> ������������.
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

/* ��������� ����϶�.
�ش����� �̸��� �Լ��ȿ� ���Ǹ� �����Ͽ� �ش����� ��µǵ��ϸ����
Full    Rect   Window Stair
y01234x
0#####  #####  #####  #
1#####  #   #  # # #  ##
2#####  #   #  #####  ###
3#####  #   #  # # #  ####
4#####  #####  #####  ##### */
//1.��Ģ�� ã�´�.
//Rect(y,x) (1,1)(1,2)(1,3) (2,1)(2,2)(2,3) (3,1)(3,2)(3,3) 1~3
//Window  (1,1)(1,3) (3,1)(3,3) -> Ȧ��
//Stair '#' (0,0) (1,0)(1,1) (2,0)(2,1)(2,2) 
//		    (3,0)(3,1)(3,2)(3,3) (4,0)(4,1)(4,2)(4,3)
//2.��Ģ��� ������ ��� �ش�.
//
//3.��Ģ���� ���ϸ��� �κ��� ������ ã�´�.
//��Stair�� (���ǹ����̰���) -> y�� �����Ҷ����� x�� ���� �����Ѵ�.
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
	//�ּ�: �����Ϸ��� �м������ʴ� ����.
	//ctrl+f5: ������(����)+����׾��� �����ϱ�
	//printf("Hello Wolrd!\n");//\n:�ٹٲ޹���.
	//printf("khg");//;(�����ݷ�) ���峡�� ��Ÿ���� ��ȣ
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