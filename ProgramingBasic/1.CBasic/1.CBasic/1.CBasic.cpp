#include <stdio.h>//ǥ�������

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
	
	float area = radius * radius * pi;
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

void main()
{
	//�ּ�: �����Ϸ��� �м������ʴ� ����.
	//ctrl+f5: ������(����)+����׾��� �����ϱ�
	//printf("Hello Wolrd!\n");//\n:�ٹٲ޹���.
	//printf("khg");//;(�����ݷ�) ���峡�� ��Ÿ���� ��ȣ
	//CircleAreaMain();
	SizeMain();
}