#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MAXN 5010
#define INF INT_MAX

using namespace std;
typedef long long ll;

int n,m;
int mat[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];

void mul(int a[MAXN][MAXN],int b[MAXN][MAXN])
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				int temp;
				if(a[i][k]==INF||b[k][j]==INF)
					temp=INF;
				else
					temp=a[i][k]+b[k][j];
				c[i][j]=min(c[i][j],temp);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=c[i][j];
}

void pow(int a[MAXN][MAXN],int k)
{
	k--;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			b[i][j]=a[i][j];
		}
	while(k>0)
	{
		if(k&1)
			mul(b,a);
		mul(a,a);
		k>>=1;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
				mat[i][j]=INF;
		}
	while(m--)
	{
		int u,v,t;
		scanf("%d%d%d",&u,&v,&t);
		mat[u][v]=mat[v][u]=t;
	}
	pow(mat,50);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			b[i][j]=a[i][j];
	for(int i=1;i<=50;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				ans[j][k][i]=INF;
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
			mul(b,a);
		for(int i=1;i<=i;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					ans[j][k][i]=min(ans[j][k][i],b[j][k]);
	}
	int s,t,k;
	while(~scanf("%d%d%d",&s,&t,&k))
	{
		if(b[s][t]==INF)
			printf("-1\n");
		else
			printf("%d\n",ans[s][t][k]);
	}
	return 0;
}
