#include<iostream>
using namespace std;

 void swap(int &a,int &b)
{
	int temp;
	 temp=a;
	 a=b;
	 b=temp;
}


void Selective_sort(int *array, const int len)
{
	int i,j;
	int min_index;
	
	for(i=0;	i<len;	i++)
	{
		//查找最小值
		min_index=i;
		for(j=i+1;	j<len;	j++)
			if(array[j]<array[min_index])
				min_index=j;				

		if(min_index != i)
			swap(array[min_index],array[j]);
	}
}


int main()
{
	int i;
	int num_test[]={9,6,7,2,10,4,3,1,8,5};
	Selective_sort(num_test,10);
	
	for(i=0;	i<10;	i++)
		cout<<num_test[i]<<"  ";
	cout<<endl;
}
