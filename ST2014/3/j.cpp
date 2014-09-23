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
#define MAXN 15
#define MAXM 225

typedef long long ll;
using namespace std;

int n,m,t,s,e,em;
ll ans;
int head[MAXN],vis[MAXM],dig[MAXN];
ll trea[MAXN];

struct edge{
	int to,next,w;
}edges[MAXM];

void addedge(int u,int v,int w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	head[u]=em++;
}

void dfs(int u,int now,ll mon){
	if(u==e){
		ans=max(ans,mon);
	}
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!vis[e]&&now+edges[e].w<=t){
			if(trea[v]!=0&&dig[v]==0){
				dig[v]=1,vis[e]=1;
				dfs(v,now+edges[e].w,mon+trea[v]);
				dig[v]=0;vis[e]=0;
			}else{
				vis[e]=1;
				dfs(v,now+edges[e].w,mon);
				vis[e]=0;
			}
		}
	}
}

int main(){
	while(~scanf("%d%d%d",&n,&m,&t)){
		scanf("%d%d",&s,&e);
		memset(trea,0,sizeof(trea));
		for(int i=0;i<n;i++)
			scanf("%lld",&trea[i]);
		memset(head,-1,sizeof(head));
		em=0;
		while(m--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		addedge(n,s,0);
		addedge(s,n,0);
		memset(dig,0,sizeof(dig));
		memset(vis,0,sizeof(vis));
		ans=0;
		dfs(n,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
