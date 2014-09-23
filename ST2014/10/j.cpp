#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<sstream>
#include<string>
#define MAXN 10005
#define MAXM 100005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXN],dfn[MAXN],low[MAXN],belong[MAXN],in[MAXN],ins[MAXN],vis[MAXN],vii[MAXN][MAXN];
int ind,em,cnt,sti;
int st[MAXN];

struct edge{
	int to,next,from;
}edges[MAXM];

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].from=u;
	edges[em].to=v;
	head[u]=em++;
}

void tarjan(int u){
	dfn[u]=low[u]=++ind;
	ins[u]=1;
	st[sti++]=u;
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[v],low[u]);
		}else if(ins[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		cnt++;
		int t;
		do{
			t=st[sti-1];
			ins[t]=0;
			sti--;
			belong[t]=cnt;
		}while(t!=u);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n,m;
		scanf("%d%d",&n,&m);
		cnt=em=ind=sti=0;
		memset(head,-1,sizeof(head));
		memset(dfn,0,sizeof(dfn));
		memset(in,0,sizeof(in));
		memset(ins,0,sizeof(ins));
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		for(int i=0;i<=cnt;i++)
			for(int j=0;j<=cnt;j++)
				vii[i][j]=0;
		for(int i=0;i<em;i++)
			if(belong[edges[i].from]!=belong[edges[i].to])
				in[belong[edges[i].to]]++;
		int ans=0;
		for(int i=1;i<=cnt;i++)
			if(in[i]==0)
				ans++;
		printf("Case %d: %d\n",cas,ans);
	}
	return 0;
}
