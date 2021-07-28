#include <stdio.h>

int g_nData;//전역변수: 모든함수에서 접근가능한 변수.

void CountData()
{
	int nData = 0;//지역변수: 지역변수는 함수를 벗어나면 사라지는 변수. 유지되지않으므로 다른 변수에 접근이 불가능하다.//6 //12 //19
	static int nStaticData = 0;//정적지역변수:함수를 벗어나도 값이 유지되는 변수.//7 
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
	printf("CountDataMain::g_nData:%d\n", g_nData);//전역변수는 어느함수에서나 쉽게 사용가능하다. //23. 3
	//함수가 다르므로 접근할수없는 변수.
	//printf("CountDataMain::nStaticData:%d\n", nStaticData); 
	//printf("CountDataMain::nData:%d\n", nData); //
}

void main()//1
{
	CountDataMain(); //2
	printf("main::g_nData:%d:\n", g_nData); //24. 3
}

