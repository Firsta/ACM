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

int out[1010],p[1010];

struct edge
{
	int u,v,w;
	int index;
}edges[2001010];

bool cmp(const edge &x,const edge &y)
{
	if(x.w<y.w)
		return 1;
	else
		return 0;
}

int find(int x)
{
	if(p[x]==x)
		return p[x];
	else
	{
		p[x]=find(p[x]);
		return p[x];
	}
}

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	while(k--)
	{
		int temp;
		scanf("%d",&temp);
		out[temp]=1;
	}
	for(int i=0;i<n;i++)
	{
		edges[i].u=0;edges[i].v=i+1;edges[i].w=0;
		edges[i].index=i;
	}
	int len=m+n;
	for(int i=n;i<len;i++)
	{
		int ut,vt,wt;
		scanf("%d%d%d",&ut,&vt,&wt);
		edges[i].u=ut;edges[i].v=vt;edges[i].w=wt;
		edges[i].index=i;
	}
	ll ans=0;
	for(int i=0;i<=n;i++)
		p[i]=i;
	sort(edges,edges+len,cmp);
	for(int i=0;i<n;i++)
	{
		edge e=edges[i];
		if(out[e.v])
			p[e.v]=e.u;
	}
	for(int i=n;i<len;i++)
	{
		edge e=edges[i];int x=find(e.u);int y=find(e.v);
		if(x!=y)
		{
			ans+=e.w;
			p[x]=y;
		}
	}
	printf("%d\n",ans);
	return 0;
}
