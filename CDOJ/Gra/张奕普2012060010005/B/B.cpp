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
#define MAXN 100010
#define MAXM 100010

typedef long long ll;
using namespace std;

int head[MAXN],next[MAXM],deg[MAXN],ind;
set<int> se[MAXN];

struct edge
{
	int from,to,next;
}edges[MAXM];

int dfn[MAXN],low[MAXN];

void tarjan(int x,int fa)
{
	low[x]=dfn[x]=++ind;
	for(int e=head[x];e!=-1;e=edges[e].next)
	{
		int temp=edges[e].to;
		if(temp!=fa)
		{
			if(!dfn[temp])
				tarjan(temp,x);
			low[x]=min(low[temp],low[x]);
		}
	}
}

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		memset(head,-1,sizeof(head));
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		memset(deg,0,sizeof(deg));
		ind=0;
		for(int i=1;i<=n;i++)
			se[i].clear();
		int em=0;
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(!se[u].count(v))
			{			
				edges[em].next=head[u];
				edges[em].from=u;
				edges[em].to=v;
				head[u]=em++;
				se[u].insert(v);
				edges[em].next=head[v];
				edges[em].from=v;
				edges[em].to=u;
				edges[em].from=v;
				head[v]=em++;
				se[v].insert(u);
			}
		}
		tarjan(1,0);
		for(int i=1;i<=n;i++)
			se[i].clear();
		for(int i=0;i<em;i++)
		{
			int u,v;
			u=edges[i].from;
			v=edges[i].to;
			if(!se[u].count(v))
			{
				if(low[u]!=low[v])
				{
					deg[low[u]]++;
					deg[low[v]]++;
					se[u].insert(v);
					se[v].insert(u);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(deg[i]==1)
				ans++;
		ans=(ans+1)/2;
		printf("%d\n",ans);
	}
	return 0;
}
