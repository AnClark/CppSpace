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
		tail->next=p;			//新结点接到链尾
		tail=p;				//尾指针到链尾
	}


	//链表以NULL收尾
	tail->next=NULL;
	
	//返回链表头。
	//本例中，链表头是访问链表的唯一依据！
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

	cout<<endl;

}


void insert_item(node *head, const int key, const int newdata)
{
	//插入新结点，需要分类讨论
	//先查找关键字
	node *p=head->next;
	node *q;
	node *newnode;	
	bool found=false;

	//情形一：关键字是链表的第一项，则插入到表头
	if(p->data == key)
	{
		newnode= new node;
		newnode->data=newdata;

		newnode->next=head->next;		
		head->next=newnode;
	}
	//情形二：关键字在链表中，则插入到关键字的前一项
	else
	{
		while((p != NULL) && (p->next != NULL))
		{
			q=p->next;
			if(q->data == key){
				newnode = new node;
				newnode->data=newdata;
				
				p->next=newnode;				
				newnode->next=q;

				found=true; break;
			}
			p=p->next;
		}
	}
	//情形三：关键字不在链表中，则搜索算法已经将工作指针移到了链表的最后。将新项目插入到链表最后
	if(!found)
	{

		//找到链表的最后一项
		while(p->next != NULL)
			p=p->next;
		
		newnode = new node;
		newnode->data = newdata;
		
		p->next=newnode;
		newnode->next=NULL;
		
	}
	
}

int main()
{
	node *fy_head;
	fy_head=gen_chain();
	
	cout<<endl;
	print_chain(fy_head);		

	int key,newdata;
	cin>>key>>newdata;
	insert_item(fy_head, key, newdata);

	cout<<endl;
	print_chain(fy_head);	

	delete fy_head;

	return 0;
}

