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
#define MAXN 1005
#define MAXM 100005
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int,int> pii;

int head[MAXN],head2[MAXN],d[MAXN],d2[MAXN];
int n,m,x;

struct edge{
	int to,next,w;
}edges[MAXM],edges2[MAXM];
int em,em2;

void addedge(int u,int v,int w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	head[u]=em++;
}

void addedge2(int u,int v,int w){
	edges2[em2].next=head2[u];
	edges2[em2].to=v;
	edges2[em2].w=w;
	head2[u]=em2++;
}

void init(){
	fill(head,head+n+1,-1);
	fill(head2,head2+n+1,-1);
	em=em2=0;
}

int main(){
	scanf("%d%d%d",&n,&m,&x);
	init();
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge2(v,u,w);
	}
	priority_queue< pii,vector<pii>,greater<pii> > q;
	fill(d,d+n+1,INF);
	d[x]=0;
	q.push(pii(0,x));
	while(!q.empty()){
		pii now=q.top();q.pop();
		int u=now.second,dt=now.first;
		if(d[u]<dt)
			continue;
		for(int e=head[u];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(d[v]>dt+edges[e].w){
				d[v]=dt+edges[e].w;
				q.push(pii(d[v],v));
			}
		}
	}
	fill(d2,d2+n+1,INF);
	d2[x]=0;
	q.push(pii(0,x));
	while(!q.empty()){
		pii now=q.top();q.pop();
		int u=now.second,dt=now.first;
		if(d2[u]<dt)
			continue;
		for(int e=head2[u];e!=-1;e=edges2[e].next){
			int v=edges2[e].to;
			if(d2[v]>dt+edges2[e].w){
				d2[v]=dt+edges2[e].w;
				q.push(pii(d2[v],v));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,d[i]+d2[i]);
	printf("%d\n",ans);
	return 0;
}
