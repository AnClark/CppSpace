/*
【【【致命警告！！！】】】
编译器一定别用GCC！
编译器一定别用GCC！！
编译器一定别用GCC！！！
这货不支持C++的众多特性，如类！
*/


#include<stdio.h>
#include<iostream>

using namespace std;


//基类
class baseClass
{
public:			//一般地，私有成员只能由类的成员函数访问。为了初步学习继承，我把所有成员设置为公有
	int baseMember1;
	int baseMember2;
	int baseMember3;


	//构造函数要先声明，而后再重写
	//但是构造函数以外的成员函数就不允许这样了
	baseClass(int,int,int);
	baseClass();
			
	
};

//重写构造函数
baseClass::baseClass(int baseVal1, int baseVal2, int baseVal3)
{
	baseMember1 = baseVal1;
	baseMember2 = baseVal2;
	baseMember3 = baseVal3;
}

//重写默认构造函数
baseClass::baseClass()
{
	cout<<"现在执行的是默认构造函数";
}


//派生类
class deriveClass : public baseClass
{
public:			//一般地，私有成员只能由类的成员函数访问。为了初步学习继承，我把所有成员设置为公有
	
	int deriveMember1;
	int deriveMember2;

	//声明构造函数
	deriveClass(int,int,int,int,int);
	deriveClass();
};

//重写派生类构造函数
deriveClass::deriveClass(int baseVal1, int baseVal2, int baseVal3, int deriveVal1, int deriveVal2)
	:baseClass(baseVal1,baseVal2,baseVal3)		//注意，引用基类的部分写的是变量名，而不是像初次声明函数那样只写变量类型！
{
	deriveMember1 = deriveVal1;
	deriveMember2 = deriveVal2;
}

//重写派生类默认构造函数
/*
deriveClass::deriveClass()
{
}
*/

int main()
{
	baseClass testBase(1111,2222,3333);
	deriveClass testDerive(5555,6666,7777,8888,9999);

	cout<<"===========基类成员如下========="<<endl;
	cout<<testBase.baseMember1<<endl;
	cout<<testBase.baseMember2<<endl;
	cout<<testBase.baseMember3<<endl;
	cout<<"==============================="<<endl<<endl;

	cout<<"==========派生类成员如下========"<<endl;
	cout<<testDerive.baseMember1<<endl;
	cout<<testDerive.baseMember2<<endl;
	cout<<testDerive.baseMember3<<endl;
	cout<<testDerive.deriveMember1<<endl;
	cout<<testDerive.deriveMember2<<endl;
	cout<<"==============================="<<endl<<endl;

	return 0;
}
