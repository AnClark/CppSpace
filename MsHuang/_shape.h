#include<iostream>
#include<stdio.h>
using namespace std;

//���ࣺ���� 
class Rectangle
{
	protected:
		int a;		//���γ�
		int b;		//���ο�
	public:
		Rectangle(const int val_a,const int val_b) ;		//�вι��캯�� 
		Rectangle();			//Ĭ�Ϲ��캯��
		//virtual ~Rectangle();		//Ĭ����������
		
		//������һ���Ա����
		int getSquare()		//�󣨵ף����
		{
			return a * b;
		} 
		int getCircum()		//���ܳ���Circumference�� 
		{
			return a * 2 + b * 2;
		}
};

//���ࣺ������ 
class Cuboid : public Rectangle
{
	private:
		int h;		//������ĸ�
	public:
		Cuboid(const int val_a, const int val_b, const int val_h) ;		//�вι��캯��
		Cuboid();		//Ĭ�Ϲ��캯��	
		//virtual ~Cuboid();			//Ĭ����������
		
		//������һ���Ա����
		int getVolume()		//�����
		{
			return a * b * h;
		} 
		int getCircum()		//���ܳ���Circumference�� 
		{
			return a * 4 + b * 4 + h * 4;
		}
};


