#include "_shape.h"

Rectangle::Rectangle(const int val_a,const int val_b) 
{
	a=val_a;
	b=val_b;
	
	//���棡���캯��û�з���ֵ�� 
}

Rectangle::Rectangle()
{
	
}

//��������
Rectangle::~Rectangle()
{
	delete Rectangle;
}
 
Cuboid::~Cuboid()
{
	delete Cuboid;
}
/*
//��Ա�����ǲ��ǲ���д��������棿 
Rectangle::int getSquare()
{
	return a * b;
}

Rectangle::int getCircum()
{
	return a * 2 + b * 2;
}
*/


 


Cuboid::Cuboid(const int val_a, const int val_b, const int val_h) 
	: Rectangle(val_a,val_b)
	{
		
	}
	
int main()
{
	Rectangle *aaa = new Rectangle(16,9);
	Cuboid *bbb = new Cuboid(4,3,5);
	
	return 0;
}
