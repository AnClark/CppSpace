#include<iostream>
#include<cstring>
using namespace std;

class memberID
{
	private:
		long value;
	public:
		memberID(long id=0)
		{
			value=id;
			cout<<"赋给会员的编号："<<value<<endl;
		}
		
		~memberID()
		{
			cout<<"删除编号："<<value<<endl;
		}
};

class member
{
	private:
		memberID id;
		char name[20];
	public:
		member(char *mname="No Name",long mid=0):id(mid)
		{
			strcpy(name,mname);
			cout<<"建立会员名："<<name<<endl;
		}
		~member()
		{
			cout<<"删除会员名："<<name<<endl;
		}
};

int main()
{
	member("爱拼安小匠",350274701);
	
	return 0;
}
