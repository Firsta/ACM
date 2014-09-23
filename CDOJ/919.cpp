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
#define INF 100

typedef long long ll;
using namespace std;

int vis[20005],head[20005],em;

struct edge
{
	int to,cap,rev,next;
}edges[10000005];

void addedge(int u,int v)
{
	edges[em].next=head[u];
	edges[em].cap=1;
	edges[em].to=v;
	edges[em].rev=em+1;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].cap=0;
	edges[em].to=u;
	edges[em].rev=em-1;
	head[v]=em++;
}

int dfs(int s,int t,int f)
{
	if(s==t)
		return f;
	vis[s]=1;
	for(int e=head[s];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(!vis[v]&&edges[e].cap>0)
		{
			int d=dfs(v,t,min(f,edges[e].cap));
			if(d>0)
			{
				edges[e].cap-=d;
				edges[edges[e].rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=m+n+1;i++)
		head[i]=-1;
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		addedge(a,b+n);
	}
	for(int i=1;i<=n;i++)
		addedge(0,i);
	for(int i=1;i<=m;i++)
		addedge(i+n,m+n+1);
	int ans=0;
	for(;;)
	{
		for(int i=0;i<=m+n+1;i++)
			vis[i]=0;
		int f=dfs(0,m+n+1,INF);
		if(f==0)
			break;
		else
			ans+=f;
	}
	printf("%d\n",ans);
	return 0;
}
