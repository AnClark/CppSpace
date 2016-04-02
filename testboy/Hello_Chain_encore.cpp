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
	node *p=head->next;		//工作指针，指向链表第一项
	node *q;			//辅助工作指针，在情形二使用
	node *newnode;			//新结点
	bool found=false;		//标识变量，如果关键字不在链表中，则值为false，以启动情形三的处理过程

	//情形一：关键字是链表的第一项，则插入到表头
	if(p->data == key)
	{
		//创建新结点
		newnode= new node;
		newnode->data=newdata;

		newnode->next=head->next;	  //新结点接到链首	
		head->next=newnode;		  //头指针指向新的链首——新结点
	}
	//情形二：关键字在链表中，则插入到关键字的前一项
	else
	{
		//根据课本的算法：工作指针指向关键字的*前一项*，辅助工作指针指向关键字
		while((p != NULL) && (p->next != NULL))		//遍历链表各项，以找出关键字
		{
			q=p->next;		//辅助指针指向关键字
			if(q->data == key){
				//创建新结点
				newnode = new node;
				newnode->data=newdata;
				
				p->next=newnode;	//关键字前一项接到新结点			
				newnode->next=q;	//新结点接到关键字处

				found=true; break;	//情形二成立，处理完毕，设置标识变量并跳出循环，以结束整个过程
			}
			p=p->next;		//继续遍历直到找到关键字/到达链尾
		}
	}
	//情形三：关键字不在链表中。我们规定，将新项目插入到链表最后
	if(!found)
	{

		//找到链表的最后一项
		while(p->next != NULL)
			p=p->next;
		
		//创建新结点
		newnode = new node;
		newnode->data = newdata;
		
		p->next=newnode;		//链尾接到新结点
		newnode->next=NULL;		//新结点成为新的链尾，链表结束，故接到空指针
		
	}
	
}

int main()
{
	//测试一	生成链表
	node *fy_head;
	fy_head=gen_chain();
	
	//测试二	输出链表
	cout<<endl;
	print_chain(fy_head);		

	//测试三	插入链表项并输出修改后的链表
	int key,newdata;
	cin>>key>>newdata;
	insert_item(fy_head, key, newdata);

	cout<<endl;
	print_chain(fy_head);	

	//善后	删除头指针，释放内存
	delete fy_head;

	return 0;
}

