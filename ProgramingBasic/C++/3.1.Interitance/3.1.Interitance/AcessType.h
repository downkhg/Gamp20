#pragma once

class CParent
{
private:
	int nPrivateData;
protected:
	int nProtectedData;
public:
	int nPublicData;
};
//�ڽ�Ŭ���� �ȿ����� ��ӹ��� Ÿ�԰� ������� ����� ���ٹ���� �ٲ����ʴ´�.
//�ܺο��� �����Ҷ���, ��ӹ����� Ÿ���� public����� proteced�� �ȴ�.
// 
//������ �����Ͽ� ������ �´°����� ����� ���� Ȯ���ϰ� �����Ѵ�.
//1.�ڽ�Ŭ�������� ������� ���ٰ����ϰ�, �ܺο��� ���ٰ����ϸ� public X
//2.�ڽ�Ŭ�������� ������� ���ٰ����ϰ�, �ܺο��� ������ �Ұ����ϸ� proteced O
//3.�ڽ�Ŭ�������� ������� ���� �Ұ����ϰ�, �ܺο��� ���ٺҰ����ϸ� private X
//������ ������� �������� �����̾ƴ϶� ���� ����� ������ �� ������� �����Ѵ�.
class CChildePrivate : private CParent
{
public:
	//int GetPrivate(){ return nPrivateData;}
	int GetProtecte() { return nProtectedData; } //protected
	int GetPublic() { return nPublicData; }//public 
};

class CChildeProteced : protected CParent
{
public:
	//int GetPrivate(){ return nPrivateData;}
	int GetProtecte() { return nProtectedData; }//protected
	int GetPublic() { return nPublicData; }//public 
};

class CChildePublic : public CParent
{
public:
	//int GetPrivate(){ return nPrivateData;}
	int GetProtecte() { return nProtectedData; }//protected
	int GetPublic() { return nPublicData; }//public 
};

void InhertanceClassTypeTest()
{
	CChildePrivate cChildePrivate;
	CChildeProteced cChildeProteced;
	CChildePublic cChildePublic;

	cChildePrivate.GetProtecte();
	//cChildePrivate.nPublicData = 10;
	//cChildePrivate.nProtectedData = 20;

	cChildeProteced.GetProtecte();
	//cChildeProteced.nPublicData = 10;
	//cChildeProteced.nProtectedData = 20;

	cChildePublic.GetPublic();
	cChildePublic.nPublicData = 10;
	//cChildeProteced.nProtectedData = 20;
}