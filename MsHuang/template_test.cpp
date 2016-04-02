#include<iostream>
using namespace std;

template <typename A> A maxnum(const A *array,const int count)
{
	int i;
	A buff=array[0];
	for(i=0; i<count; i++)
		if ((array[i])>buff)
			buff=array[i];
	
	return buff;
}

int ia[]={99,5,63,2,474,70};
double da[]={22.3,86.4,55.7,74.2,63.5};


int main()
{
	int i=maxnum<int>(ia,5);
	double j=maxnum<double>(da,5);
	
	cout<<"整数的最大值是："<<'\t'<<i<<endl;
	cout<<"双精度实数最大值是："<<'\t'<<j<<endl;
	
	return 0;
}


