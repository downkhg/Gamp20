#include <stdio.h>

int g_nData;//��������: ����Լ����� ���ٰ����� ����.

void CountData()
{
	int nData = 0;//��������: ���������� �Լ��� ����� ������� ����. �������������Ƿ� �ٸ� ������ ������ �Ұ����ϴ�.//6 //12 //19
	static int nStaticData = 0;//������������:�Լ��� ����� ���� �����Ǵ� ����.//7 
	nData++; //8.0++ = 1 //13.0++ = 1 //20 0++ =1
	nStaticData++; //8. 0++ = 1 //14.1++ = 1 //21. 2++ = 3
	g_nData++; //9. 0++ = 1 //15. 1++=1 //22. 2++ = 3
	printf("CountData::g_nData:%d\n",g_nData);  //1 //1 //3
	printf("CountData::nStaticData:%d\n", nStaticData); //1 //2 //3
	printf("CountData::nData:%d\n", nData);  //1 //2 //3
}

void CountDataMain()
{
	for (int i = 0; i < 3; i++) //3. 0 //10. 1 //16.2
	{
		printf("####### %d #######\n",i);//4. 0 //11. 1 //17.1
		CountData(); //5. //12 //18
	}
	printf("CountDataMain::g_nData:%d\n", g_nData);//���������� ����Լ������� ���� ��밡���ϴ�. //23. 3
	//�Լ��� �ٸ��Ƿ� �����Ҽ����� ����.
	//printf("CountDataMain::nStaticData:%d\n", nStaticData); 
	//printf("CountDataMain::nData:%d\n", nData); //
}

void main()//1
{
	CountDataMain(); //2
	printf("main::g_nData:%d:\n", g_nData); //24. 3
}

