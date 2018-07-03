/*
*�������ߣ�������� 
*���ʱ�䣺2018/7/2 
*�����ܣ�ʹ��ѭ�����н��Լɪ�����⡣ 
*/ 
#include<stdio.h>
#define MAX 50
#define FALSE 0
#define TRUE 1

//ѭ�����е����Ͷ���
typedef struct				
{
	int element[MAX];		//���е�Ԫ�ؿռ�
	int front;				//ͷָ��ָʾ��
	int rear;				//βָ��ָʾ��
	int	num; 				//����Ԫ�ظ��� 
}SeqQueue;

//��ʼ��ѭ������ 
void InitQueue(SeqQueue *Q)
{	//��*Q��ʼ��Ϊһ���յ�ѭ������
	Q->front=Q->rear=0;
	Q->num=0;
}

//ѭ��������Ӳ���
int EnterQueue(SeqQueue *Q,int x)
{
	if((Q->rear+1)%MAX==Q->front)		//βָ���1׷��ͷָ�룬��־�����Ѿ�����
		return(FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAX;			//�������ö�βָ��
	return(TRUE);
}

//ѭ�����г���
int DeleteQueue(SeqQueue *Q,int *x)		//ɾ�����еĶ�ͷԪ�أ���x������ֵ
{
	if(Q->front==Q->rear)				//����Ϊ��
		return(FALSE);
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAX;			//�������ö�ͷָ��
	return(TRUE);						//�����ɹ�
}

//��ȡ��ͷԪ�� 
int GetHead(SeqQueue *Q,int *x)
{
	if(Q->front==Q->rear)				//����Ϊ��
		return(FALSE);
	else
	{
		*x=Q->element[Q->front];			
		return(TRUE);
	}
}

/*��̭����*/
void OutPeople(SeqQueue *Q,int n)
{
	int count;
	while(1)
	{
		if(Q->num==1)	break; 	//�ж��Ƿ�ֻ��һ������Ԫ�� 
		count=1;
		while(count<n)
		{
			EnterQueue(Q,Q->element[Q->front]);	//��3�ı������ 
			DeleteQueue(Q,&Q->element[Q->front]);			//���� 
			count++;
		}
		printf("��̭->%d\n",Q->element[Q->front]);
		DeleteQueue(Q,&Q->element[Q->front]);	//��̭��ͷ 
		Q->num--;		//��������1
	}
}

int main()
{
	SeqQueue Q;
	InitQueue(&Q);
	int i,number,winner;
	printf("����:\n");
	scanf("%d",&number);
	getchar(); 
	for(i=0;i<number;i++)		//����� 
		EnterQueue(&Q,i+1);
	Q.num=number;				//��ʼ��Ϊ������ 
	OutPeople(&Q,3); 
	GetHead(&Q,&winner);		//��ȡ��ͷԪ�أ���ʤ�� 
	printf("��ʤ���ǣ�%d\n",winner);
	return 0;
}
