#include<iostream>
using namespace std;

int InsertSort(int nums[],int n)			//nΪ��Ŀ�� 
{
	int i,j,k;			//ѭ������
	int temp=0;			//���ÿ�����ڱȽϵ��� 
	int temp_swap;
	
	for(i=0;	i<n;	i++)
	{
		for(j=i+1;	j<n;	j++)
		{
			if(temp>nums[j])
			{
				//nums[i]=0;
				for(k=j;	k<i;	k++)
				{
					temp_swap=nums[k];
					nums[k]=nums[k+1];
					nums[k+1]=temp_swap;
				}
				temp=nums[j];
				break;
			}
		}
	}
	
	return 0;
} 


int main()
{
	int i;
	int num_test[]={9,6,7,2,10,4,3,1,8,5};
	InsertSort(num_test,10);
	
	for(i=0;	i<10;	i++)
		cout<<num_test[i]<<"  ";
	cout<<endl;
	
	return 0;
}
