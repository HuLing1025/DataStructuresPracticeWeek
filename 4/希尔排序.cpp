/*
*�������ߣ�������� 
*���ʱ�䣺2018/7/3 
*�����ܣ����ϣ����������� 
*/ 
#include<stdio.h>
#define MAX 20

/*�Լ�¼����r��һ��ϣ����������lengthΪ����ĳ��ȣ�deltaΪ���� */
void ShellInsert(int r[],int length,int d)
{
	int i,j;
	for(i=1+d;i<=length;i++)				//1+deltaΪ��һ�������еĵڶ���Ԫ�ص��±�
	if(r[i]<r[i-d])
	{
		r[0]=r[i];							//����r[i](����������)
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
	printf("��������������������\n");
		scanf("%d",&length);
	printf("��������������飺\n"); 
	for(i=1;i<=length;i++)
		scanf("%d",&r[i]);
	for(i=length;i>1;count++)
	{
		i=i/2;
		delta[count]=i;
	}
	for(i=0;i<count;i++)
	{
		ShellInsert(r,length,delta[i]);		//ѭ������ShellInsert����ϣ������
		printf("��%d����������\n",i+1);
		for(j=1;j<=length;j++)				//���ÿ������Ľ��
			printf("%d ",r[j]);
		printf("\n");
	}
	return 0;
}
