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

typedef long long ll;
using namespace std;

ll G[1005][1005],t[100005];
int fa[1005*1005],vis[1005][1005],ans[100005];
int n,m;

struct building
{
	int x,y;
	ll h;
}b[1005*1005];

int cmp(const struct building &a,const struct building &b)
{
	if(a.h>b.h)
		return 1;
	else
		return 0;
}

int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}

void init()
{
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			vis[i][j]=0;
	for(int i=0;i<=n*m+1;i++)
		fa[i]=i;
}

int main()
{
	int z;
	cin>>z;
	while(z--)
	{
		cin>>n>>m;
		int k=0;
		init();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				b[k].x=i;
				b[k].y=j;
				cin>>G[i][j];
				b[k++].h=G[i][j];
			}
		sort(b,b+n*m,cmp);
/*		for(int i=0;i<n*m;i++)
			cout<<b[i].h<<' ';
		cout<<endl;*/
		int tn;
		cin>>tn;
		for(int i=0;i<tn;i++)
			cin>>t[i];
		int j=0,sum=0;
		for(int i=tn-1;i>=0;i--)
		{
			while(b[j].h>t[i]&&j<n*m)
			{
				int u=b[j].x,v=b[j].y;
				vis[u][v]=1;
				sum++;
				if(vis[u-1][v]&&find(((u-1)-1)*m+v)!=(u-1)*m+v)
				{
					fa[find((u-1-1)*m+v)]=(u-1)*m+v;
					sum--;
				}
				if(vis[u+1][v]&&find((u+1-1)*m+v)!=(u-1)*m+v)
				{
					fa[find((u+1-1)*m+v)]=(u-1)*m+v;
					sum--;
				}
				if(vis[u][v-1]&&find((u-1)*m+(v-1))!=(u-1)*m+v)
				{
					fa[find((u-1)*m+(v-1))]=(u-1)*m+v;
					sum--;
				}
				if(vis[u][v+1]&&find((u-1)*m+(v+1))!=(u-1)*m+v)
				{
					fa[find((u-1)*m+(v+1))]=(u-1)*m+v;
					sum--;
				}
				j++;
			}
			ans[i]=sum;
		}
		for(int i=0;i<tn;i++)
			cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}
