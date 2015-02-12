#include<cstdio>
#include<cstring>
#include<cstdlib>
const int MAXN=25;
int q[25][25];
int top[25];
char s1[5],s2[5];
int b1,b2;
void find(int *a,int *b,int c,int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<top[i];j++)
		if(q[i][j]==c)
		{
			*a=i;
			*b=j;
			return;
		}
	}
}
void clear(int a,int b)
{
	for(int i=b+1;i<top[a];i++)
	{
		q[q[a][i]][0]=q[a][i];
		top[q[a][i]]++;
	}
	top[a]=b+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(top,0,sizeof(0));
	for(int i=0;i<n;i++)
	{
		q[i][0]=i;
		top[i]++;
	}
	for(;;)	
	{
	        scanf("%s",s1);
		if(!strcmp(s1,"quit"))
			break;
		scanf("%d",&b1);
		scanf("%s",s2);
		scanf("%d",&b2);
		if(b1==b2)
			continue;
		int x1,y1,x2,y2;
		find(&x1,&y1,b1,n);
		find(&x2,&y2,b2,n);
		int temp;
		temp=q[x1][y1];
		if(x1==x2)
			continue;
		if(!strcmp(s1,"move")&&!strcmp(s2,"onto"))
		{
			clear(x1,y1);
			clear(x2,y2);
			q[x2][y2+1] =temp;
			top[x1]--;
			top[x2]++;
		}
		if(!strcmp(s1,"move")&&!strcmp(s2,"over"))
		{
			clear(x1,y1);
			q[x2][top[x2]]=temp;
			top[x2]++;
			top[x1]--;
		}
		if(!strcmp(s1,"pile")&&!strcmp(s2,"onto"))
		{
			int d=top[x1]-y1;
			clear(x2,y2);
			top[x2]=y2+d+1;
			for(int i=0;i<d;i++)
			{
				q[x2][y2+i+1]=q[x1][y1+i];
			}
			top[x1]=y1;
		}
		if(!strcmp(s1,"pile")&&!strcmp(s2,"over"))
		{
			for(int i=y1;i<top[x1];i++)
			{
				q[x2][top[x2]]=q[x1][i];
				top[x2]++;
			}
			top[x1]=y1;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d:",i);
		for(int j=0;j<top[i];j++)
		{
			printf(" %d",q[i][j]);
		}
		printf("\n");
	}
	return 0;
}
