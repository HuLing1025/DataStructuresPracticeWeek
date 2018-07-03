/*
*程序作者：胡令、杨柳 
*完成时间：2018/7/3
*程序功能：构建哈夫曼树并输出其哈夫曼编码。 
*/ 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 20
#define M 2*N-1

typedef char *HuffmanCode;

typedef struct{
	char c;
	int info;
}Seqlist;

/*结点类型声明*/ 
typedef struct
{
	int weight;		//结点权值 
	int parent;		//双亲结点下标 
	int LChild;		//左孩子结点下标 
	int RChild;		//右孩子结点下标 
}HTNode,HuffmanTree;

/*录入权值*/ 
int crtWeght(Seqlist *w)
{
	int i,n;
	printf("请输入要输入字母的个数:");
	scanf("%d",&n);
	getchar();
	printf("请输入要输入的权值及字母(使用逗号隔开):\n");
	for(i=1;i<=n;i++)
		scanf("%d,%c",&w[i].info,&w[i].c);
	return n;
}

/*在1到i-1中找出最小的两个结点权值最小的下标保存到s1,s2*/ 
void select(HuffmanTree *ht,int n,int *s1,int *s2)
{
	int i,min;
	for(i=1;i<=n;i++)
	{
		if(ht[i].parent==0)
		{
			min=i;
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(ht[i].parent==0)
		{
			if(ht[i].weight<ht[min].weight)
				min=i;
		}
	}
	(*s1)=min;
	for(i=1;i<=n;i++)
	{
		if(ht[i].parent==0&&i!=(*s1))
		{
			min=i;
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(ht[i].parent==0&&i!=(*s1))
		{
			if(ht[i].weight<ht[min].weight)
				min=i;
		}
	}
	(*s2)=min;
}

/*建立哈夫曼树*/
void CrtHuffmanTree(HuffmanTree *ht,Seqlist w[],int n)
{
	int i ,m,s1,s2;
	for(i=0;i<=n;i++)
	{
		ht[i].weight=w[i].info;
		ht[i].parent=0;
		ht[i].LChild=0;
		ht[i].RChild=0;
	};
	m=2*n-1;
	for(i=n+1;i<=m;i++)
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].LChild=0;
		ht[i].RChild=0;
	}
	for(i=n+1;i<=m;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i;
		ht[s2].parent=i;
		ht[i].LChild=s1;
		ht[i].RChild=s2;
	}
}

/*哈夫曼编码函数*/
void CrtHuffmanCode(HuffmanTree *ht,HuffmanCode *hc,Seqlist *w, int n)
{
	char *cd;
	int c,p,i,j,start;
	cd=(char *)malloc(n * sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;
		c=i;p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].LChild==c) cd[start]='0';
			else cd[start]='1';
			c=p;p=ht[p].parent;
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(hc[i],&cd[start]);
		for(j=1;j<=n;j++)
		{
			if(w[j].info==ht[i].weight)
			{
				printf("字母为%c的编码为:",w[j].c);
				puts(hc[i]);
			}
		}
	}
	free(cd);
}

int main()
{
	int n;
	HuffmanCode hc[N+1];
	Seqlist w[M+1];
	HuffmanTree ht[M+1];
	n=crtWeght(w);			//录入权值 
	CrtHuffmanTree(ht,w,n);		//建树 
	CrtHuffmanCode(ht,hc,w,n);	//哈夫曼编码 
	return 0;
}
