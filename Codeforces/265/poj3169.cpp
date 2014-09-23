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
#define INF 100000000000
#define MAXV 1005
#define MAXE 50005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int cnt[MAXV],head[MAXV],inq[MAXV];
ll d[MAXV];
int n,ml,md;

struct edge{
	int to,next;
	ll w;
}edges[MAXE];
int em;

void addedge(int u,int v,ll w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	head[u]=em++;
}

void init(){
	em=0;
	scanf("%d%d%d",&n,&ml,&md);
	fill(head,head+n,-1);
	while(ml--){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		addedge(u-1,v-1,w);
	}
	while(md--){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		addedge(v-1,u-1,-w);
	}
}

bool negetiveCycle(){
	queue<int> q;
	fill(d,d+n,INF);
	fill(cnt,cnt+n,0);
	fill(inq,inq+n,0);
	d[0]=0;inq[0]=1;
	q.push(0);
	while(!q.empty()){
		int now=q.front();q.pop();
		inq[now]=0;
		for(int e=head[now];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(d[v]>d[now]+edges[e].w){
				d[v]=d[now]+edges[e].w;
				if(!inq[v]){
					inq[v]=1;
					if(++cnt[v]>n)
						return true;
					q.push(v);
				}
			}
		}
	}
	return false;
}

void judge(){
	if(negetiveCycle())
		printf("-1\n");
	else if(d[n-1]==INF)
		printf("-2\n");
	else
		printf("%d",d[n-1]);
}

int main(){
	init();
	judge();
	return 0;
}
