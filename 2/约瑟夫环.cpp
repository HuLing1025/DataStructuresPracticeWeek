/*
*程序作者：胡令、杨柳 
*完成时间：2018/7/2 
*程序功能：使用循环队列解决约瑟夫环问题。 
*/ 
#include<stdio.h>
#define MAX 50
#define FALSE 0
#define TRUE 1

//循环队列的类型定义
typedef struct				
{
	int element[MAX];		//队列的元素空间
	int front;				//头指针指示器
	int rear;				//尾指针指示器
	int	num; 				//队列元素个数 
}SeqQueue;

//初始化循环队列 
void InitQueue(SeqQueue *Q)
{	//将*Q初始化为一个空的循环队列
	Q->front=Q->rear=0;
	Q->num=0;
}

//循环队列入队操作
int EnterQueue(SeqQueue *Q,int x)
{
	if((Q->rear+1)%MAX==Q->front)		//尾指针加1追上头指针，标志队列已经满了
		return(FALSE);
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAX;			//重新设置队尾指针
	return(TRUE);
}

//循环队列出队
int DeleteQueue(SeqQueue *Q,int *x)		//删除队列的队头元素，用x返回其值
{
	if(Q->front==Q->rear)				//队列为空
		return(FALSE);
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAX;			//重新设置队头指针
	return(TRUE);						//操作成功
}

//获取对头元素 
int GetHead(SeqQueue *Q,int *x)
{
	if(Q->front==Q->rear)				//队列为空
		return(FALSE);
	else
	{
		*x=Q->element[Q->front];			
		return(TRUE);
	}
}

/*淘汰函数*/
void OutPeople(SeqQueue *Q,int n)
{
	int count;
	while(1)
	{
		if(Q->num==1)	break; 	//判断是否只有一个队列元素 
		count=1;
		while(count<n)
		{
			EnterQueue(Q,Q->element[Q->front]);	//非3的倍数入队 
			DeleteQueue(Q,&Q->element[Q->front]);			//出队 
			count++;
		}
		printf("淘汰->%d\n",Q->element[Q->front]);
		DeleteQueue(Q,&Q->element[Q->front]);	//淘汰队头 
		Q->num--;		//人数减少1
	}
}

int main()
{
	SeqQueue Q;
	InitQueue(&Q);
	int i,number,winner;
	printf("人数:\n");
	scanf("%d",&number);
	getchar(); 
	for(i=0;i<number;i++)		//入队列 
		EnterQueue(&Q,i+1);
	Q.num=number;				//初始化为总人数 
	OutPeople(&Q,3); 
	GetHead(&Q,&winner);		//获取队头元素，即胜者 
	printf("获胜者是：%d\n",winner);
	return 0;
}
