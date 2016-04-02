#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}


void Selective_Sort(int *unsorted, int count)
{
	int i,j;
	int index;
	
	//for(i=0;	i<count;	i++)
	for(i=0;	i<count;	i++)				//貌似不管有没有-1，结果都一样 
	{
		index=i;
		
		for(j=i+1;	j<count;	j++)
			if(unsorted[j]<unsorted[index])
				index=j;
		//if(index != i)		//貌似不管有没有这一句，结果都一样 
			swap(unsorted[i],unsorted[index]);
	}
	
}




int main()
{
	int num_test[]={9,2,6,7,4,1,3,5,8,10};
	Selective_Sort(num_test,10);
	
	int i;
	for(i=0;	i<10;	i++)
		cout<<*(num_test+i)<<'\t';
	
	return 0;
}
