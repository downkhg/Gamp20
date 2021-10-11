#pragma once

#include <iostream>
using namespace std;
//������ ���� �������� Ư¡�� �Ӽ��� ���� ���۸� �����ϴ� Ŭ������ ���� ��Ӱ���� �����ʿ䰡 ����.
namespace Inheritance
{
	//1�����̶�� ��ü�� ��������.
	struct Vector//��ü: ����(2���� ��ġ)
	{
		//public:
		float x;
		float y;
		Vector(float x = 0, float y = 0)
		{
			this->x = x;
			this->y = y;
		}
		void Print(const char* msg)
		{
			cout << msg << "(" << x << "," << y << ")" << endl;
		}
	};

	class Shape //����:
	{
	public:
		Shape()
		{
			cout << "Shape[" << this << "]" << endl;
		}
		~Shape()
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		void Draw()
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//���� ���� �ﰢ��,�簢���� Ŭ������ �����
	class Circle : public Shape
	{
		Vector vPos;
		float fRadius;
	public:
		Circle(Vector pos = Vector(), float rad = 1)
		{
			cout << "Circle[" << this << "]" << endl;
			vPos = pos;
			fRadius = rad;
			
			cout << "Rad:" << fRadius << endl;
		}
		~Circle()
		{
			cout << "~Circle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "Circle[" << this << "]::Draw()" << endl;
			vPos.Print("Pos");
			cout << "Rad:" << fRadius << endl;
		}
	};
	class TriAngle : public Shape
	{
		Vector vA;
		Vector vB;
		Vector vC;
	public:
		TriAngle(Vector a = Vector(), Vector b = Vector(), Vector c = Vector()) { cout << "TriAngle[" << this << "]" << endl; };
		~TriAngle() { cout << "TriAngle[" << this << "]" << endl; };
		void Draw()
		{
			cout << "TriAngle[" << this << "]::Draw()" << endl;
			vA.Print("A:");
			vB.Print("B:");
			vC.Print("C:");
		}
	};
	class RectAangle : public Shape
	{
		Vector vTL;
		Vector vTR;
		Vector vBL;
		Vector vBR;
	public:
		RectAangle(Vector tl = Vector(), Vector tr = Vector(), Vector bl = Vector(), Vector br = Vector())
		{
			cout << "RectAangle[" << this << "]" << endl;
			vTL = tl;
			vTR = tr;
			vBL = bl;
			vBR = br;
		}
		~RectAangle()
		{
			cout << "~RectAangle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vTL.Print("TopLeft:");
			vTR.Print("TopRight:");
			vBL.Print("BottomLeft:");
			vBR.Print("BottomRight:");
		}
	};

	//�θ��� �κа� �ڽ��� �κ��� �޸𸮰� �ٸ���. 
	//�ᱹ ����� ���ؼ� �ΰ��� �����̸��� �Լ��� ������.
	void ShapeMain()
	{
		Shape cShape;
		Circle cCrilce({ 1,1 }, 1);
		cShape.Draw();
		cShape.Shape::Draw();//�θ��� ����Լ��� ȣ��
		cCrilce.Draw();
		cCrilce.Shape::Draw();//�θ��� ����Լ��� ȣ��
	}
	//���α׷� �����߿� �����Ͽ� ����� �������� �׸����� ����ؾ��ϴ°�?//�������� �޸𸮸� �Ҵ�޾ƾ��Ѵ�.
	void RuntimeShapeDrawMain()
	{
		void** arrShape;
		arrShape = new void*[3];
	
		arrShape[0] = (void*)new Circle();
		arrShape[1] = (void*)new RectAangle();
		arrShape[2] = (void*)new TriAngle();
		//������ ��ü�� ������ ĳ�����ϸ� ���ŷӰ� ���� �迭�� ������ ������ ã���ƴ�.
		for (int i = 0; i < 3; i++)
			((Shape*)arrShape[i])->Draw();
		((Circle*)arrShape[0])->Draw();
		((RectAangle*)(arrShape[1]))->Draw();
		((TriAngle*)(arrShape[2]))->Draw();
	}
	//�θ�Ŭ������ �Լ��� virtual�� ���̸� �����Լ����ǰ�,
	//�θ������Ϳ����� �ڽ��� ���� �̸����Լ��� ȣ�Ⱑ��������.
	void PolymrphismShapeDrawMain()
	{
		Shape* arrShape[3];

		arrShape[0] = new Circle();
		arrShape[1] = new RectAangle();
		arrShape[2] = new TriAngle();

		for (int i = 0; i < 3; i++)
			arrShape[i]->Draw();

		for (int i = 0; i < 3; i++)
			delete(arrShape[i]);
	}
}