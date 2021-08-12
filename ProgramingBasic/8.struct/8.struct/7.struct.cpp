#include <stdio.h>
#include <string.h>
//����ü: ��������� ���� , ������, ������, �迭
//��Ÿ������ ����� ���� 1���̻����� ��Ÿ�����ϴ� ��� ����ü�� ����ϸ� ���ϴ�.
//�߻�ȭ: ��Ÿ�� ����� ������ȭ�ϴ� ��.
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
	//sPlayer.strName = "test";//�����Ͽ���
	//����ü�� �������� ������ ������ �����Ƿ� 1���� �ʱ�ȭ�ؾ��Ѵ�.
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
	//sPlayer.strName = "test";//�����Ͽ���
	//����ü�� �������� ������ ������ �����Ƿ� 1���� �ʱ�ȭ�ؾ��Ѵ�.
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
	//����: ��(������)�� �����ϴ� ��.
	//����ü�� �ڷ������� �Ͽ� ������ �����Ѵ�.
	//������ ���� ������ �ʱ�ȭ�� �����ϳ� �⺻�ɹ������� ������ �°� �����͸� �־���Ѵ�.
	SPlayer sPlayer = { "test", 100, 100, 10, 10 };
	//sPlayer.strName = "test";//�����Ͽ���
	//����ü�� �������� ������ ������ �����Ƿ� 1���� �ʱ�ȭ�ؾ��Ѵ�.
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