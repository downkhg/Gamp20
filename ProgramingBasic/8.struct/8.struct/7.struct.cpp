#include <stdio.h>
#include <string.h>

//����ü: ��������Ǻ��� Ÿ��
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
	//sPlayer.strName = "test";//�����Ͽ���
	//����ü�� �������� ������ ������ �����Ƿ� 1���� �ʱ�ȭ�ؾ��Ѵ�.
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
	//����: ��(������)�� �����ϴ� ��.
	//����ü�� �ڷ������� �Ͽ� ������ �����Ѵ�.
	//������ ���� ������ �ʱ�ȭ�� �����ϳ� �⺻�ɹ������� ������ �°� �����͸� �־���Ѵ�.
	SPlayer sPlayer = { "test", 100, 100, 10, 10};
	//sPlayer.strName = "test";//�����Ͽ���
	//����ü�� �������� ������ ������ �����Ƿ� 1���� �ʱ�ȭ�ؾ��Ѵ�.
	strcpy(sPlayer.strName, "test");
	sPlayer.nHP = 100;
	sPlayer.nMP = 100;
	sPlayer.nAtk = 10;
	sPlayer.nDef = 10;
	PrintPlayer(sPlayer);
	SPlayer sPlayer2 = InitPlayer("test2", 100, 100, 10, 10);
	PrintPlayer(sPlayer2);
}