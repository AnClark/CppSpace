/*
【【【致命警告！！！】】】
■与构造函数不同，成员函数不能在类的声明之外重写！
	成员函数不能在类的声明之外重写！！
	成员函数不能在类的声明之外重写！！！
■析构函数不允许只声明而不重写！
■在派生类中写与基类对应成员同名的函数，其结果就是“同名覆盖”——实际执行的函数是你在派生类中写的函数，且基类中的代码并没有执行！
■成员函数不像构造函数那样能够继承，正如G++提示：only constructors take member initializers ！！！

*/

#include<iostream>
#include<string>
using namespace std;


//基类
class baseClass
{
	//成员：指定为字符串数组，以便于输出
	string baseMember[5];

public:
	//声明构造函数
	baseClass(string,string,string,string,string);
	//声明默认构造函数
	baseClass();
	//声明析构函数
	//~baseClass();
	
	//声明成员函数：打印输出所有成员
	int getMembers()
	{
		int i;		//循环变量
		cout<<"======归属于基类的所有成员========"<<endl;
		for(i=0; i<5; i++)
			cout<<"成员"<<i<<"：	"<<baseMember[i]<<endl;
		cout<<"==========================="<<endl;

		return 0;
	}


};

//重写基类构造函数
baseClass::baseClass(string Val0, string Val1, string Val2, string Val3, string Val4)
{
	//给成员变量赋值
	baseMember[0] = Val0;
	baseMember[1] = Val1;
	baseMember[2] = Val2;
	baseMember[3] = Val3;
	baseMember[4] = Val4;	
}



//派生类
class deriveClass : public baseClass
{
	//派生类特有成员
	int deriveMember[5];
	
public:
	//声明构造函数
	deriveClass(string,string,string,string,string,  int,int,int,int,int);
	//声明默认构造函数
	deriveClass();
	//声明析构函数
	//~deriveClass();

	//多态实践——————同名覆盖基类中的成员函数：打印输出所有成员
	int getMembers()
	//int getMembers() : baseClass.getMembers()		//此写法是错误的
	{
		int i;		//循环变量
		cout<<"==========归属于派生类的所有成员========"<<endl;
		for(i=0; i<5; i++)
			cout<<"成员"<<i<<"：	"<<deriveMember[i]<<endl;
		cout<<"======================================"<<endl;	


		return 0;
	}

};

//重写派生类构造函数
deriveClass::deriveClass(string Val0, string Val1, string Val2, string Val3, string Val4, 
			int Val5, int Val6, int Val7, int Val8, int Val9)
		:baseClass(Val0, Val1, Val2, Val3, Val4)
{
	deriveMember[0]=Val5;
	deriveMember[1]=Val6;
	deriveMember[2]=Val7;
	deriveMember[3]=Val8;
	deriveMember[4]=Val9;	
}


int main()
{
	baseClass testBase("aaaaa","bbbbb","ccccc","ddddd","eeeee");
	deriveClass testDerive("vvvvv","wwwww","xxxxx","yyyyy","zzzzz",11111,22222,33333,44444,55555);	

	cout<<"	现	在	输	出	基	类	成	员	"<<endl;
	testBase.getMembers();
	cout<<endl;
	cout<<"	现	在	输	出	派	生	类	成	员	"<<endl;
	testDerive.getMembers();


	return 0;
}
