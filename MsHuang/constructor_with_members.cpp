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
			cout<<"������Ա�ı�ţ�"<<value<<endl;
		}
		
		~memberID()
		{
			cout<<"ɾ����ţ�"<<value<<endl;
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
			cout<<"������Ա����"<<name<<endl;
		}
		~member()
		{
			cout<<"ɾ����Ա����"<<name<<endl;
		}
};

int main()
{
	member("��ƴ��С��",350274701);
	
	return 0;
}
