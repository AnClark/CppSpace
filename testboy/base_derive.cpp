#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;


//基类
class baseClass
{
public:			//一般地，私有成员只能由类的成员函数访问。为了初步学习继承，我把所有成员设置为公有
	string baseMember1;
	string baseMember2;
	int baseMember3;


	//先声明函数，而后再重写
	baseClass(string,string,int);
	baseClass();
			
	
};

//重写构造函数
baseClass::baseClass(string baseVal1, string baseVal2, int baseVal3)
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
	
	string deriveMember1;
	int deriveMember2;

	//声明构造函数
	deriveClass(string,string,int,string,int);
	deriveClass();
};

//重写派生类构造函数
deriveClass::deriveClass(string baseVal1, string baseVal2, int baseVal3, string deriveVal1, int deriveVal2)
	:baseClass(baseVal1,baseVal2,baseVal3)		//注意，这里写的是变量名，而不是像初次声明函数那样只写变量类型！
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
	baseClass testBase("基类成员一号","基类成员二号",9999);
	deriveClass testDerive("继承基类成员一号","继承基类成员二号",5555,"派生类独有成员一号",2222);

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
