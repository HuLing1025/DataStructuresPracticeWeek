/*
*�������ߣ�������� 
*���ʱ�䣺2018/7/2 
*�����ܣ����һԪ����ʽ�ļӷ����㡣 
*/ 
#include<stdio.h>
#include<malloc.h>

/*һԪ����ʽ��ʽ�洢���ṹ������*/ 
typedef struct Polynode{
	int coef;	//ϵ��
	int exp;	//ָ��
	struct Polynode* next; 	//ָ����ָ����һ��� 
}PolyNode,*Polylist; 

/*��β�巨����һԪ����ʽ������*/
Polylist PolyCreate()
{
	PolyNode* head,*rear,*s;
	int c,e;
	printf("�������ʽ��ϵ����ָ����ʹ��Ӣ�Ķ��Ÿ�������0��0������\n");
	head=(PolyNode*)malloc(sizeof(PolyNode));                      //��������ʽ��ͷ���
	rear=head;													//rearʼ��ָ�������β������β�巨����
	scanf("%d,%d",&c,&e);									//�������ʽ��ϵ����ָ����
	while(c!=0)												//��c=0����������ʽ���������
	{
		s=(PolyNode *)malloc(sizeof(PolyNode));				//�����µĽ��
		s->coef=c;
		s->exp=e;
		rear->next=s;										//�ڵ�ǰ��β������
		rear=s;
		scanf("%d,%d",&c,&e);
	}
	rear->next=NULL;										//��������һ������next��NULL����ʾ�����
	return(head);
}

/*һԪ����ʽ�ӷ�*/ 
void PolyAdd(Polylist head1,Polylist head2)
{
	PolyNode *p,*q,*last,*t;	//t:�����ͷ��ڴ� 
	int coef_sum;			//ϵ����
	p=head1->next;			//pָ�����ʽ1�ĵ�һ����� 
	q=head2->next; 			//qָ�����ʽ2�ĵ�һ����� 
	last=head1;				//lastָ��Ͷ���ʽ�����һ�����
	while(p!=NULL&&q!=NULL) //������һ������ʽɨ����ɺ��˳�ѭ�� 
	{
		if(p->exp<q->exp)
		/*��ָ��С�Ķ���ʽ���뵽last����,���룺p*/
		{
			last->next=p;
			last=p;
			p=p->next;
		}//if 
		else if(p->exp==q->exp)
		/*ָ�����*/
		{
			coef_sum=p->coef+q->coef;
			if(coef_sum!=0)	//ϵ��֮�Ͳ�����0
			/*�޸�p��ָ���ϵ�������뵽last֮���ͷ�q��ָ���*/
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
			/*ϵ������0���ͷ����������*/
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
		/*ָ��С�Ķ���ʽ���뵽last���棬���룺q*/
		{
			last->next=q;
			last=q;
			q=q->next;
		}//else
	}//while
	if(p!=NULL)		//�����ʱ����һ������ʽ����ʣ�࣬����last֮��
		last->next=p;
	else
		last->next=q;
}

/*��ӡ�������*/
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
	/*��������ʽ*/ 
	head1=PolyCreate();		
	head2=PolyCreate();		
	/*�������ʽ1��2*/ 
	printf("Y1="); 			
	showList(head1);
	printf("Y2="); 
	showList(head2);
	/*�ӷ����� */
	PolyAdd(head1,head2);	
	/*����Ͷ���ʽ*/
	printf("Y1+Y2="); 		 
	showList(head1);
	return 0;
}
