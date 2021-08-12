#include <stdio.h>
#include <string.h>

//구조체: 사용자정의변수 타입
//나타내야할 대상이 변수 1개이상으로 나타내야하는 경우 구조체를 사용하면 편리하다.
//추상화: 나타낼 대상을 데이터화하는 것.
struct SPlayer
{
	char strName[24];
	int nHP;
	int nMP;
	int nDef;
	int nAtk;
};

SPlayer InitPlayer(const char* name, int hp, int mp, int def, int atk)
{
	SPlayer sPlayer;
	//sPlayer.strName = "test";//컴파일오류
	//구조체는 여러개의 변수를 가지고 있으므로 1개씩 초기화해야한다.
	strcpy(sPlayer.strName, name);
	sPlayer.nHP = hp;
	sPlayer.nMP = mp;
	sPlayer.nDef = def;
	sPlayer.nAtk = atk;
	return sPlayer;
}
void PrintPlayer(SPlayer sPlayer)
{
	printf("Name:%s\n", sPlayer.strName);
	printf("HP:%s\n", sPlayer.nHP);
	printf("MP:%s\n", sPlayer.nMP);
	printf("Def:%s\n", sPlayer.nDef);
	printf("Atk:%s\n", sPlayer.nAtk);
}
void main()
{
	//변수: 값(데이터)을 저장하는 것.
	//구조체를 자료형으로 하여 변수를 생성한다.
	//다음과 같이 생성시 초기화가 가능하나 기본맴버변수에 순서에 맞게 데이터를 넣어야한다.
	SPlayer sPlayer = { "test", 100, 100, 10, 10};
	//sPlayer.strName = "test";//컴파일오류
	//구조체는 여러개의 변수를 가지고 있으므로 1개씩 초기화해야한다.
	strcpy(sPlayer.strName, "test");
	sPlayer.nHP = 100;
	sPlayer.nMP = 100;
	sPlayer.nAtk = 10;
	sPlayer.nDef = 10;
	PrintPlayer(sPlayer);
	SPlayer sPlayer2 = InitPlayer("test2", 100, 100, 10, 10);
	PrintPlayer(sPlayer2);
}