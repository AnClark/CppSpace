#include<iostream>
#include<stdio.h>
using namespace std;

//基类：矩形 
class Rectangle
{
	protected:	//注意继承关键字！如果写成private，就根本没法访问！ 
		int a;		//矩形长
		int b;		//矩形宽
	public:
		Rectangle(const int val_a,const int val_b) ;		//有参构造函数 
		Rectangle();			//默认构造函数
		//virtual ~Rectangle();		//默认析构函数
		
		//功能性一般成员函数
		int getSquare()		//求面积
		{
			return a * b;
		} 
		int getCircum()		//求周长（Circumference） 
		{
			return a * 2 + b * 2;
		}
};

//子类：长方体 
class Cuboid : public Rectangle
{
	private:
		int h;		//长方体的高
	public:
		Cuboid(const int val_a, const int val_b, const int val_h) ;		//有参构造函数
		Cuboid();		//默认构造函数	
		//virtual ~Cuboid();			//默认析构函数
		
		//功能性一般成员函数
		int getVolume()		//求体积
		{
			return a * b * h;
		} 
		int getCircum()		//求周长（Circumference） ——要重写基类的函数~~~ 
		{
			return a * 4 + b * 4 + h * 4;
		}
		int getSquare_all()		//求总面积 
		{
			return a * b * 2 + a * h * 2 + b * h * 2;
		}
};


