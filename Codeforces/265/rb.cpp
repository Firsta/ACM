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
#include<utility>
#define MAXE 200005
#define MAXV 5005
#define INF 100000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int,int> pii;

int head[MAXV],d[MAXV],d2[MAXV];

struct edge{
	int to,next,w;
}edges[MAXE];
int em;

void addedge(int u,int v,int w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	edges[em].w=w;
	head[v]=em++;
}

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	memset(head,-1,sizeof(head));
	em=0;
	while(r--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	priority_queue< pii,vector<pii>,greater<pii> > q;
	fill(d,d+n+1,INF);
	fill(d2,d2+n+1,INF);
	d[0]=0;
	q.push(pii(0,1));
	while(!q.empty()){
		pii now=q.top();q.pop();
		if(now.first>d2[now.second])
			continue;
		for(int e=head[now.second];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(d[v]>now.first+edges[e].w){
				d[v]=now.first+edges[e].w;
				q.push(pii(d[v],v));
			}
			if(d2[v]>now.first+edges[e].w&&now.first+edges[e].w>d[v]){
				d2[v]=now.first+edges[e].w;
				q.push(pii(d2[v],v));
			}
		}
	}
	printf("%d",d2[n]);
	return 0;
}
