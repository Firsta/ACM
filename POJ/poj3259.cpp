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
#define MAXN 505
#define MAXM 6000
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n,m,w;
int head[MAXN],d[MAXN],cnt[MAXN],inq[MAXN];

struct edge{
	int to,next,w;
}edges[MAXM];
int em;

void addedge(int u,int v,int w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	head[u]=em++;
}

void init(){
	fill(head,head+n,-1);
	em=0;
}

bool floyd(int s,int d[]){
	queue<int> q;
	fill(inq,inq+n,false);
	fill(cnt,cnt+n,0);
	fill(d,d+n,INF);
	q.push(s);
	inq[s]=1;
	d[s]=0;
	cnt[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=0;
		for(int e=head[u];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(d[v]>d[u]+edges[e].w){
				d[v]=d[u]+edges[e].w;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
					if(++cnt[v]>n)
						return true;
				}
			}
		}
	}
	return false;
}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&w);
		init();
		while(m--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u-1,v-1,w);
			addedge(v-1,u-1,w);
		}
		while(w--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u-1,v-1,-w);
		}
		if(floyd(0,d))
			printf("YES\n");
		else if(d[0]<0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
