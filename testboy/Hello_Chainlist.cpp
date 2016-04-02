/*******************************************
	LEARN HOW TO USE CHAINLIST
	April 1st, 2016
********************************************/


#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;

struct node
{
	int data;
	node *next;	
	
};

node *gen_chain()
{
	int n;				//Receive user input
	node *head, *tail, *p;
	
	//Generate first item
	head = new node;
	tail=head;
	
	while(cin>>n)
	{
		p = new node;
		
		p->data=n;
		
		tail->next=p;
		tail=p;
	}
	
	tail->next=NULL;
	
	return head;
}


void print_chain(const node *head)
{
	node *p=head->next;
	while(p != NULL)
	{
		cout<<p->data<<'\t';
		p=p->next;
	}
	
}

bool search_item(const int key, const node *head)
{
	node *p=head->next;
	
	//THE FOLLOWING ARITHMETIC HAS A PROBLEM. USE THE FOLLOWING ONE INSTEAD.
	/*
		WARNING!
		Without the check of NULL pointer, the program will crash when your key is not found!
		NULL pointer is dangerous!
	*/
	/*
	while((p->data != key) && (p->next != NULL))
		p=p->next;
		
	if(p->next == NULL)
		return false;
	else
		return true;
	*/
	
	/*
	// Scan from HEAD to the one before the last one
	while(p->next != NULL)
	{
		if(p->data == key)
			return true;
		p=p->next;
	}
	//Check if the last one matches
	if((p->next == NULL) && (p->data == key))
		return true;
	
	return false;
	*/
	
	while(p != NULL)
	{
		if(p->data == key)
			return true;
		p=p->next;
	}
	
	return false;
}

/*
bool remove_item(const int key, const node *head)
{
	node *p;
	node *q=head->next;
	//bool found=false;

	while(q != NULL)
	{
		p=q->next;
		if(p->data == key)
			q->next=p->next;
		q=q->next;
	}

}
*/

/*
	Removal code
	By huahuahailang (http://blog.csdn.net/huahuahailang/article/details/8762785)
*/
node *remove_item(node *head,int key)
{
	node *node1=head;
	node *node2=NULL;
	if (head==NULL)
	{
		return NULL;
	} 
	else
	{
		if (node1->data==key)
		{
			head=head->next;
			free(node1);
			return head;
		} 
		else
		{
			while (node1!=NULL)
			{
				//node2=node1;
				//node2=node2->next;
				node2=node1->next;
				if (node2->data==key)
				{
					node1->next=node2->next;
					free(node2);
					break;
				}
				node1=node1->next;
			}
			return head;
		}
	}
}

/*
bool remove_item_fy(const node *head, int key)
{
	node *p=head;
	node *q;
	
	//If the first one is what we'd remove
	if(head->data == key)
	{
		head
	}
	
} 
*/
int main()
{
	node *fy_head;
	fy_head=new node;
	
	cout<<"Input a sequence which will be values of a new chain."<<endl;
	cout<<"When finished, Press Ctrl+Z."<<endl;
	
	fy_head=gen_chain();
	print_chain(fy_head);
	
	
	int *key=new int(0);
	cout<<endl;
	cout<<"Well done, man. Now let's start a search!"<<endl;
	cout<<"Input a key:";
	/* WARNING!
	 Pointer cannot be used in cin stream!
	 Must use scanf instead. No need of the opreator &, as the parameter itself is a mem address.
	*/
	scanf("%d",key);
	//cin>>*key;
	
	bool found=search_item(*key,fy_head);
	switch (found){
		case true :
			cout<<"Lucky guy! Your key is exist!"<<endl;
			break;
		default :
			cout<<"Uh-oh! You haven't input the key..."<<endl;
	}
	
	/*
	cout<<endl;
	cout<<"Time to remove a item! Pick an integer you want to remove."<<endl;
	scanf("%d",key);
	bool remove_ok=remove_item(*key,fy_head);
	switch (remove_ok){
		case true :
			cout<<"Yeah! The item has been removed!"<<endl;
			cout<<"Now re-print the list!"<<endl;
			print_chain(fy_head);
			break;
		default :
			cout<<"Uh-oh! You haven't input the key..."<<endl;
	}	
	*/
	
	cout<<endl;
	cout<<"Time to remove a item! Pick an integer you want to remove."<<endl;
	scanf("%d",key);
	fy_head=remove_item(fy_head, *key);
			cout<<"Removal performed."<<endl;
			cout<<"Now re-print the list!"<<endl;
			print_chain(fy_head);	
	
	delete fy_head;
	
}
