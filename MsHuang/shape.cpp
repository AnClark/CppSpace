#include "_shape.h"

Rectangle::Rectangle(const int val_a,const int val_b) 
{
	a=val_a;
	b=val_b;
	
	//警告！构造函数没有返回值！ 
}

Rectangle::Rectangle()
{
	
}

//析构函数怎么写？得问问老师啊。。。重试了N次都通不过编译。。。 
/*
Rectangle::~Rectangle()
{
	delete Rectangle;
}
 
Cuboid::~Cuboid()
{
	delete Cuboid;
}
*/
/*
//成员函数是不是不能写在类的外面？ 
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
		h=val_h;
	}
	
int main()
{
	Rectangle *aaa = new Rectangle(16,9);
	Cuboid *bbb = new Cuboid(4,3,5);
	
	cout<<"============矩	形================"<<endl;
	cout<<"面积：	"<< aaa->getSquare() <<endl;
	cout<<"周长：	"<< aaa->getCircum() <<endl;
	cout<<endl;
	
	cout<<"============长	方	体===================="<<endl;
	cout<<"底面积：	"<< bbb->getSquare() <<endl;
	cout<<"总面积：	"<< bbb->getSquare_all() <<endl;
	cout<<"周长：	"<< bbb->getCircum() <<endl;
	cout<<"体积：	"<< bbb->getVolume() <<endl; 
	
	delete aaa;
	delete bbb;
	
	return 0;
}
