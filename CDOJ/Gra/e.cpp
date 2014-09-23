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
#define MAXN 400010
#define MAXM 400010

typedef long long ll;
using namespace std;

int n,em,ind,head[MAXN],id[MAXN],vs[MAXN],depth[MAXN],endn[MAXN],sumv[MAXN];
int addv[MAXN];

struct edge
{
	int from,to,next,w;
}edges[MAXM];

void dfs(int u,int p,int d)
{
	id[u]=ind;
	vs[ind]=u;
	depth[ind++]=d;
	for(int e=head[u];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(v!=p)
			dfs(v,u,d+edges[e].w);
	}
	endn[id[u]]=ind-1; //-1
}

int dp[MAXN][30];

void rmq(int n)
{
	for(int i=1;i<=n;i++)
		dp[i][0]=depth[i];
	int m=floor(log(n*1.0)/log(2.0));
	for(int j=1;j<m;j++)
		for(int i=1;i<=n;i++)
			if(i+(1<<j)-1<=n)
			{
				dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
			}
}

int solve(int l,int r)
{
	int k=floor(log(r-l+1)/log(2.0));
	return min(dp[l][k],dp[r-(1<<k)+1][k]);
}

void maintain(int id,int l,int r)
{
	if(addv[id]!=0)
	{
		int mid=(l+r)/2;
		addv[id*2]+=addv[id];
		addv[id*2+1]+=addv[id];
		sumv[id*2]+=(mid-l+1)*addv[id];
		sumv[id*2+1]+=(r-mid)*addv[id];
		addv[id]=0;
	}
}

void build(int id,int l,int r)
{	
	int lc=id*2,rc=id*2+1;
	if(l==r)
	{
		sumv[id]=depth[l];
	}
	else
	{
		int mid=(l+r)/2;
		build(lc,l,mid);
		build(rc,mid+1,r);
		sumv[id]=sumv[lc]+sumv[rc];
	}
}

void update(int id,int l,int r,int w,int a,int b)
{
	int lc=id*2,rc=id*2+1;
	if(a<=l&&b>=r)
	{
		sumv[id]+=w*(l-r+1);
		addv[id]+=w;
	}
	else
	{
		maintain(id,l,r);
		int mid=(l+r)/2;
		if(a<=mid)
			update(lc,l,mid,w,a,b);
		if(b>mid)
			update(rc,mid+1,r,w,a,b);
		sumv[id]=sumv[lc]+sumv[rc];
	}
}

int query(int id,int l,int r,int a,int b)
{
	if(a<=l&&b>=r)
		return sumv[id];
	else
	{
		maintain(id,l,r);
		int mid=(l+r)/2;
		int ans=0;
		if(a<=mid)
			ans+=query(id*2,l,mid,a,b);
		if(b>mid)
			ans+=query(id*2+1,mid+1,r,a,b);
		return ans;
	}
}

int main()
{
	scanf("%d",&n);ind=1;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=4*n;i++)
		sumv[i]=INT_MAX;
	int em=1;
	for(int i=1;i<=n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edges[em].next=head[u];
		edges[em].w=w;
		edges[em].from=u;
		edges[em].to=v;
		head[u]=em++;
		edges[em].next=head[v];
		edges[em].w=w;
		edges[em].from=v;
		edges[em].to=u;
		head[v]=em++;
	}
	dfs(1,0,0);
	rmq(n);
/*	for(int i=1;i<=n;i++)
		cout<<vs[i]<<' '<<depth[i]<<endl;
	for(int i=1;i<=n;i++)
		cout<<end[i]<<endl;*/
	build(1,1,n);
//	for(int i=1;i<=7;i++)
//		cout<<sumv[i]<<endl;
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b);
		if(op==1)
		{
			int lca=solve(min(id[a],id[b]),max(id[a],id[b]));
//			cout<<"LCA:"<<lca<<endl; 
			int ans=query(1,1,n,id[a],id[a])+query(1,1,n,id[b],id[b])-2*depth[lca];
			cout<<ans<<endl;
		}
		if(op==2)
		{
			edge e=edges[a*2];
			int u=e.from;
			int v=e.to;
			int t=max(id[u],id[v]);
//			cout<<t<<' '<<end[t]<<endl;
			update(1,1,n,b-e.w,t,endn[t]);
//			for(int i=1;i<=5;i++)
//				cout<<i<<':'<<depth[i]<<' ';
//			cout<<endl;
		}
	}
	return 0;
}
