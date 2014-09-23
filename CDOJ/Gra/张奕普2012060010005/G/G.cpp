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
#define MAXN 1010
#define INF 10000000

typedef long long ll;
using namespace std;

int G[MAXN][MAXN];
int vis1[MAXN],vis2[MAXN],d1[MAXN],d2[MAXN];

int main()
{
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=INF;
		}
	while(m--)
	{
		int u,v,t;
		scanf("%d%d%d",&u,&v,&t);
		G[u][v]=t;
	}
	for(int i=1;i<=n;i++)
	{
		d1[i]=(i==x?0:INF);
		d2[i]=(i==x?0:INF);
	}
	for(int i=0;i<n;i++)
	{
		int temp,m=INF;
		for(int j=1;j<=n;j++)
			if(!vis1[j]&&d1[j]<=m)
				m=d1[temp=j];
		vis1[temp]=1;
		for(int j=1;j<=n;j++)
			d1[j]=min(d1[j],d1[temp]+G[temp][j]);
		m=INF;
		for(int j=1;j<=n;j++)
			if(!vis2[j]&&d2[j]<=m)
				m=d2[temp=j];
		vis2[temp]=1;
		for(int j=1;j<=n;j++)
			d2[j]=min(d2[j],d2[temp]+G[j][temp]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=x)
		{
			ans=max(ans,d1[i]+d2[i]);
		}
	}
	printf("%d\n",ans);
}
