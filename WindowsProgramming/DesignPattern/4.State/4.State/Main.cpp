#include <iostream>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���
#include "State.h"

using namespace std;

void main()
{
	//_CrtSetBreakAlloc(165); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	Context cContext;
	//�����ڿ��� �⺻ StateOne�� �Ҵ��ϰų�,
	//������ State�� �����Ҽ��ֵ��� �����ڸ� ������.
	//�Ҹ��ڿ��� ������ ��ü�� �Ҹ��Ű���� ����.

	///�ر׷��� friend�� ��������ʵ��� ������.
	//friendŰ���带 �̿��Ͽ� Context�� ��밡���ϰ� ���� ���� �ִ�.
	//�����������̽��� ����ϱ� ������
	//cContext.SetState(new StateOne());
	//Context::GoNext()�� �ٸ� ������ ��ü�� �����ǵ���,
	//Contest::SetState()���� ������ �Ҵ�� ��ü�� �����ϰ� ����.
	cContext.GoNext();
	cContext.GoNext();
	cContext.GoNext();
}