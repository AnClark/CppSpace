#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int buff=a;
	a=b;
	b=buff;
}

int main()
{
	int testarray[15]={0,0,0,0,0,1,2,3,4,5,6,7,8,9,10};
	int i,j;

	cout<<"左移前的数组:";
	for(i=0; i<15; i++)
		cout<<testarray[i]<<'\t';
	cout<<endl;


	for(i = 0 ; i<15; i++)
		swap(testarray[i],testarray[i+1]);

	cout<<"左移后的数组:";
	for(i=0; i<15; i++)
		cout<<testarray[i]<<'\t';
	cout<<endl;
}



