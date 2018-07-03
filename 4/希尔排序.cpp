/*
*程序作者：胡令、杨柳 
*完成时间：2018/7/3 
*程序功能：完成希尔排序操作。 
*/ 
#include<stdio.h>
#define MAX 20

/*对记录数组r做一趟希尔插入排序，length为数组的长度，delta为增量 */
void ShellInsert(int r[],int length,int d)
{
	int i,j;
	for(i=1+d;i<=length;i++)				//1+delta为第一个子序列的第二个元素的下标
	if(r[i]<r[i-d])
	{
		r[0]=r[i];							//备份r[i](不做监视哨)
		for(j=i-d;j>0&&r[0]<r[j];j-=d)
		{
			r[j+d]=r[j];
		}
		r[j+d]=r[0];
	}
} 

int main()
{
	int length,r[MAX],i,j,delta[MAX],count=0; 
	printf("请输入待排序数组个数：\n");
		scanf("%d",&length);
	printf("请输入待排序数组：\n"); 
	for(i=1;i<=length;i++)
		scanf("%d",&r[i]);
	for(i=length;i>1;count++)
	{
		i=i/2;
		delta[count]=i;
	}
	for(i=0;i<count;i++)
	{
		ShellInsert(r,length,delta[i]);		//循环调用ShellInsert进行希尔排序
		printf("第%d次排序结果：\n",i+1);
		for(j=1;j<=length;j++)				//输出每次排序的结果
			printf("%d ",r[j]);
		printf("\n");
	}
	return 0;
}
