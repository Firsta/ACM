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
#define INF 1000000000
#define MAXV 1005
#define MAXE 100005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

typedef pair<int,int> P;

struct edge{
	int to,cap,cost,rev,next;
}edges[MAXE];
int em;

int V;
int h[MAXV],dist[MAXV],prevv[MAXV],preve[MAXV],head[MAXV];

void addedge(int u,int v,int cap,int cost){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].cap=cap;
	edges[em].cost=cost;
	edges[em].rev=em+1;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	edges[em].cap=0;
	edges[em].cost=-cost;
	edges[em].rev=em-1;
	head[v]=em++;
}

int min_cost_flow(int s,int t,int f){
	int res=0;
	fill(h,h+V,0);
	while(f>0){
//		cout<<1<<endl;
		priority_queue< P,vector<P>,greater<P> > que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();que.pop();
			int u=p.second;
			if(dist[u]<p.first)
				continue;
			for(int e=head[u];e!=-1;e=edges[e].next){
				int v=edges[e].to;
				if(edges[e].cap>0&&dist[v]>dist[u]+edges[e].cost+h[u]-h[v]){
					dist[v]=dist[u]+edges[e].cost+h[u]-h[v];
					prevv[v]=u;
					preve[v]=e;
					que.push(P(dist[v],v));
				}
			}
		}
		if(dist[t]==INF)
			return -1;
		for(int i=0;i<V;i++)
			h[i]+=dist[i];
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
			d=min(d,edges[preve[v]].cap);
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edges[preve[v]].cap-=d;
			edges[edges[preve[v]].rev].cap+=d;
		}
	}
	return res;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	V=n;
	memset(head,-1,sizeof(head));
	while(m--){
		int u,v,cost;
		scanf("%d%d%d",&u,&v,&cost);
		addedge(u-1,v-1,1,cost);
		addedge(v-1,u-1,1,cost);
	}
	printf("%d\n",min_cost_flow(0,n-1,2));
	return 0;
}
