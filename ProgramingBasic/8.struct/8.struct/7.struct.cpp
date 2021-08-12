#include <stdio.h>
#include <string.h>
//구조체: 사용자정의 변수 , 포인터, 참조자, 배열
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
	printf("InitPlayer:%d\n", &sPlayer);
	//sPlayer.strName = "test";//컴파일오류
	//구조체는 여러개의 변수를 가지고 있으므로 1개씩 초기화해야한다.
	strcpy(sPlayer.strName, name);
	sPlayer.nHP = hp;
	sPlayer.nMP = mp;
	sPlayer.nDef = def;
	sPlayer.nAtk = atk;
	return sPlayer;
}
void InitPlayerPtr(SPlayer* pPlayer, const char* name, int hp, int mp, int def, int atk)
{
	printf("InitPlayerPtr:%d\n", pPlayer);
	//sPlayer.strName = "test";//컴파일오류
	//구조체는 여러개의 변수를 가지고 있으므로 1개씩 초기화해야한다.
	strcpy(pPlayer->strName, name);
	//(*pPlayer).nHP = hp;
	pPlayer->nHP = hp;
	pPlayer->nMP = mp;
	pPlayer->nDef = def;
	pPlayer->nAtk = atk;
}
void PrintPlayer(SPlayer sPlayer)
{
	printf("PrintPlayer[%d]\n",&sPlayer);
	printf("Name:%s\n", sPlayer.strName);
	printf("HP:%d\n", sPlayer.nHP);
	printf("MP:%d\n", sPlayer.nMP);
	printf("Def:%d\n", sPlayer.nDef);
	printf("Atk:%d\n", sPlayer.nAtk);
}
void PrintPlayerRef(SPlayer& sPlayer)
{
	printf("PrintPlayerRef[%d]\n", &sPlayer);
	printf("Name:%s\n", sPlayer.strName);
	printf("HP:%d\n", sPlayer.nHP);
	printf("MP:%d\n", sPlayer.nMP);
	printf("Def:%d\n", sPlayer.nDef);
	printf("Atk:%d\n", sPlayer.nAtk);
}

void PlayerMain()
{
	//변수: 값(데이터)을 저장하는 것.
	//구조체를 자료형으로 하여 변수를 생성한다.
	//다음과 같이 생성시 초기화가 가능하나 기본맴버변수에 순서에 맞게 데이터를 넣어야한다.
	SPlayer sPlayer = { "test", 100, 100, 10, 10 };
	//sPlayer.strName = "test";//컴파일오류
	//구조체는 여러개의 변수를 가지고 있으므로 1개씩 초기화해야한다.
	strcpy(sPlayer.strName, "test");
	sPlayer.nHP = 100;
	sPlayer.nMP = 100;
	sPlayer.nAtk = 10;
	sPlayer.nDef = 10;
	PrintPlayer(sPlayer);

	SPlayer sPlayer2 = InitPlayer("test2", 100, 100, 10, 10);
	InitPlayerPtr(&sPlayer2, "test2", 100, 100, 10, 10);
	PrintPlayerRef(sPlayer2);

	printf("Player:%d\n", &sPlayer);
	printf("Player2:%d\n", &sPlayer2);

	SPlayer arrPlayer[3];

	for (int i = 0; i < 3; i++)
	{
		char name[24];
		sprintf(name, "Test%d", i);
		InitPlayerPtr(&arrPlayer[i], name, 100, 100, 10, 10 * i);
		PrintPlayerRef(arrPlayer[i]);
	}
}

union Matrix4x4 {
	struct {
		float        _11, _12, _13, _14;
		float        _21, _22, _23, _24;
		float        _31, _32, _33, _34;
		float        _41, _42, _43, _44;

	};
	float m[4][4];
};

void UninonTestMain()
{
	Matrix4x4 mat;
	int nCount = 0;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			mat.m[y][x] = nCount;
			nCount++;
		}
	}
	printf("mat._11:%f\n", mat._11);
	printf("mat._21:%f\n", mat._21);
	printf("mat._31:%f\n", mat._31);
	printf("mat._41:%f\n", mat._41);
}

void main()
{
	PlayerMain();
	UninonTestMain();
}