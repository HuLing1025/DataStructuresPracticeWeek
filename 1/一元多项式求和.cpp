/*
*程序作者：胡令、杨柳 
*完成时间：2018/7/2 
*程序功能：完成一元多项式的加法运算。 
*/ 
#include<stdio.h>
#include<malloc.h>

/*一元多项式链式存储结点结构体声明*/ 
typedef struct Polynode{
	int coef;	//系数
	int exp;	//指数
	struct Polynode* next; 	//指针域：指向下一结点 
}PolyNode,*Polylist; 

/*用尾插法建立一元多项式的链表*/
Polylist PolyCreate()
{
	PolyNode* head,*rear,*s;
	int c,e;
	printf("输入多项式的系数和指数，使用英文逗号隔开，以0，0结束：\n");
	head=(PolyNode*)malloc(sizeof(PolyNode));                      //建立多项式的头结点
	rear=head;													//rear始终指向单链表的尾，便于尾插法建表
	scanf("%d,%d",&c,&e);									//输入多项式的系数和指数项
	while(c!=0)												//若c=0，则代表多项式的输入结束
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));				//申请新的结点
		s->coef=c;
		s->exp=e;
		rear->next=s;										//在当前表尾做插入
		rear=s;
		scanf("%d,%d",&c,&e);
	}
	rear->next=NULL;										//将表的最后一个结点的next置NULL，以示表结束
	return(head);
}

/*一元多项式加法*/ 
void PolyAdd(Polylist head1,Polylist head2)
{
	PolyNode *p,*q,*last,*t;	//t:用来释放内存 
	int coef_sum;			//系数和
	p=head1->next;			//p指向多项式1的第一个结点 
	q=head2->next; 			//q指向多项式2的第一个结点 
	last=head1;				//last指向和多项式的最后一个结点
	while(p!=NULL&&q!=NULL) //当其中一个多项式扫描完成后退出循环 
	{
		if(p->exp<q->exp)
		/*将指数小的多项式链入到last后面,链入：p*/
		{
			last->next=p;
			last=p;
			p=p->next;
		}//if 
		else if(p->exp==q->exp)
		/*指数相等*/
		{
			coef_sum=p->coef+q->coef;
			if(coef_sum!=0)	//系数之和不等于0
			/*修改p所指结点系数，链入到last之后，释放q所指结点*/
			{
				p->coef=coef_sum;
				last->next=p;
				last=p;
				p=p->next;
				t=q;
				q=q->next;
				free(t); 
			}//if 
			else
			/*系数等于0，释放这两个结点*/
			{
				t=p;
				p=p->next;
				free(t);
				t=q;
				q=q->next;
				free(t); 
			}//else 
		}//else if 
		else
		/*指数小的多项式链入到last后面，链入：q*/
		{
			last->next=q;
			last=q;
			q=q->next;
		}//else
	}//while
	if(p!=NULL)		//如果此时其中一个多项式还有剩余，链入last之后
		last->next=p;
	else
		last->next=q;
}

/*打印输出链表*/
void showList(Polylist head)
{
	Polylist p;
	p=head->next;
	while(p)
	{
		if(p!=head->next&&p->coef>0)
			printf("+"); 
		printf("%dX^%d",p->coef,p->exp);
		p=p->next;
	}
	printf("\n");
} 

int main()
{
	Polylist head1=NULL,head2=NULL;
	/*建立多项式*/ 
	head1=PolyCreate();		
	head2=PolyCreate();		
	/*输出多项式1、2*/ 
	printf("Y1="); 			
	showList(head1);
	printf("Y2="); 
	showList(head2);
	/*加法运算 */
	PolyAdd(head1,head2);	
	/*输出和多项式*/
	printf("Y1+Y2="); 		 
	showList(head1);
	return 0;
}
