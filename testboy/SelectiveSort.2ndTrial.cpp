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
	for(i=0;	i<count;	i++)				//ò�Ʋ�����û��-1�������һ�� 
	{
		index=i;
		
		for(j=i+1;	j<count;	j++)
			if(unsorted[j]<unsorted[index])
				index=j;
		//if(index != i)		//ò�Ʋ�����û����һ�䣬�����һ�� 
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
