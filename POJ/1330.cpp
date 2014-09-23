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
#define MAXN 40005
#define MAXM 40005

typedef long long ll;
using namespace std;

int n,ind,head[MAXN],in[MAXN],id[MAXN],depth[MAXN*2],vs[MAXN*2];

struct edge
{
	int to,next;
}edges[MAXM*2];

void dfs(int u,int p,int d)
{
	id[u]=ind;
	vs[ind]=u;
	depth[ind++]=d;
	for(int e=head[u];e!=-1;e=edges[e].next)
	{
		int v=edges[e].to;
		if(v!=p)
		{
			dfs(v,u,d+1);
			vs[ind]=u;
			depth[ind++]=d;
		}
	}
}

int dp[MAXN][30];

void rmq_init()
{
	for(int i=1;i<=ind;i++)
		dp[i][0]=i;
	int m=floor(log(ind*1.0)/log(2.0));
	for(int j=1;j<=m;j++)
		for(int i=1;i<=ind;i++)
			dp[i][j]=depth[dp[i][j-1]]<depth[dp[i+(1<<(j-1))][j-1]]? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
}

int solve(int l,int r)
{
	int k=floor(log((double)r-l+1)/log(2.0));
	return depth[dp[l][k]]<depth[dp[r-(1<<k)+1][k]]? dp[l][k]:dp[r-(1<<k)+1][k];
}

int LCA(int a,int b)
{
	if(id[a]>id[b])
	{
		int t=a;
		a=b;
		b=t;
	}
	return solve(id[a],id[b]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(head,-1,sizeof(head));
		memset(in,0,sizeof(in));
		int em=1;ind=1;
		for(int i=1;i<=n-1;i++)
		{
			int u,v,w;
			scanf("%d%d",&u,&v);
			edges[em].next=head[u];edges[em].to=v;
			head[u]=em++;
			in[v]++;
		}
		for(int i=1;i<=n;i++)
			if(!in[i])
				dfs(i,-1,0);
		rmq_init();
		int a,b;
		scanf("%d%d",&a,&b);
		cout<<vs[LCA(a,b)]<<endl;
	}
	return 0;
}
