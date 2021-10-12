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
//자식클래스 안에서는 상속받은 타입과 상관없이 멤버의 접근방식이 바뀌지않는다.
//외부에서 접근할때만, 상속받을때 타입이 public멤버는 proteced가 된다.
// 
//가정을 검증하여 무엇이 맞는것인지 결과를 통해 확인하고 정리한다.
//1.자식클래스에의 멤버에서 접근가능하고, 외부에서 접근가능하면 public X
//2.자식클래스에의 멤버에서 접근가능하고, 외부에서 접근이 불가능하면 proteced O
//3.자식클래스에의 멤버에서 접근 불가능하고, 외부에서 접근불가능하면 private X
//문법의 사용방법을 익힐때는 개념이아니라 실제 결과를 가지고 그 사용방법을 정리한다.
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