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
	ScoreCheckMain();
}