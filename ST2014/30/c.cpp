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
#define MAXN 2000
#define MAXM 50005
#define INF 50000000000000LL

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXN],vis[MAXN],cost[MAXN],done[MAXN];
ll dist[MAXN][MAXN];

struct edge{
	int to,next;
	ll w;
}edges[MAXM];
int em;

struct Node{
	int d,u;
	bool operator < (const Node &rhs) const{
		return d>rhs.d;
	}
};

void addedge(int u,int v,ll w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	edges[em].w=w;
	head[v]=em++;
}

void dijkstra(int s){
	priority_queue<Node> q;
	dist[s][s]=0;
	memset(done,0,sizeof(done));
	q.push((Node){0,s});
	while(!q.empty()){
		Node now=q.top();
		q.pop();
		int u=now.u;
		if(done[u])
			continue;
		done[u]=true;
		for(int e=head[u];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(dist[s][v]>dist[s][u]+edges[e].w){
				dist[s][v]=dist[s][u]+edges[e].w;
				q.push((Node){dist[s][v],v});
			}
		}
	}
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		for(int i=0;i<n;i++)
			scanf("%d",&cost[i]);
		memset(head,-1,sizeof(head));
		em=0;
		while(m--){
			int u,v;
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			addedge(u-1,v-1,w);
		}
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dist[i][j]=INF;
		fill(vis,vis+n,0);
		for(int i=0;i<n;i++){
			dijkstra(i);
			vis[i]=1;
		}
		int q;
		scanf("%d",&q);
		while(q--){
			int s,t;
			scanf("%d%d",&s,&t);
			ll ans=LLONG_MAX;
			for(int i=0;i<n;i++){
				if(dist[s][i]!=INF&&dist[i][t]!=INF)
					ans=min(ans,dist[s][i]+dist[i][t]+cost[i]);
			}
			if(ans==LLONG_MAX)
				printf("-1\n");
			else
				printf("%lld\n",ans);
		}
	}
	return 0;
}
