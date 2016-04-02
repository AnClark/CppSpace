#include<iostream>
using namespace std;


struct node
{
	int data;
	node *next;
};


node *gen_chain()
{
	int n;
	node *head, *tail, *p;

	//生成链表头
	head = new node;
	tail=head;

	//根据用户的输入，开始生成链表各项
	while((cin>>n) && (n>-1) )
	{
		//新建一个节点
		p=new node;
		p->data=n;		//填入数据

		//将链表已建立的节点与新建的节点连接起来
		//这两句我不太理解。。。。。。
		tail->next=p;
		tail=p;
	}


	//链表以NULL收尾
	tail->next=NULL;
	
	//返回链表头。
	//本例中，链表头是访问链表的唯一依据！
	return head;
}


void print_chain(node *head)
{
	node *p=head->next;
	
	while(p != NULL)
	{
		cout<<p->data<<'\t';
		p=p->next;
	}

	cout<<endl;

}


int main()
{
	node *fy_head;
	fy_head=gen_chain();
	
	cout<<endl;
	print_chain(fy_head);		
		
	delete fy_head;

	return 0;
}

