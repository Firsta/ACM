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
#define MAXV 605
#define MAXE 50000
#define INF 2

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXV],vis[MAXV];

struct edge{
	int to,next,rev,cap;
}edges[MAXE];
int em;

void addedge(int u,int v){
	edges[em].to=v;
	edges[em].next=head[u];
	edges[em].rev=em+1;
	edges[em].cap=1;
	head[u]=em++;
	edges[em].to=u;
	edges[em].next=head[v];
	edges[em].rev=em-1;
	edges[em].cap=0;
	head[v]=em++;
}

int dfs(int s,int t,int f){
	if(s==t)
		return f;
	vis[s]=1;
	for(int e=head[s];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!vis[v]&&edges[e].cap>0){
			int d=dfs(v,t,min(f,edges[e].cap));
			if(d>0){
				edges[e].cap-=d;
				edges[edges[e].rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow=0;
	for(;;){
	//	cout<<1<<endl;
		memset(vis,0,sizeof(vis));
		int f=dfs(s,t,INF);
		if(f==0)
			return flow;
		else
			flow+=f;
	}
}

int main(){
	int n,f,d;
	scanf("%d%d%d",&n,&f,&d);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		int fi,di;
		scanf("%d%d",&fi,&di);
		//1~n:cow1 n+1~2*n:cow2 2*n+1~3*n:food 3*n+1~4*n:drink
		while(fi--){
			int tf;
			scanf("%d",&tf);
			addedge(2*n+tf,i);
		}
		while(di--){
			int td;
			scanf("%d",&td);
			addedge(i+n,td+2*n+f);
		}
	}
	int s=0,tt=2*n+f+d+1;
	for(int i=1;i<=n;i++)
		addedge(i,i+n);
	for(int i=1;i<=f;i++)
		addedge(s,i+2*n);
	for(int i=1;i<=d;i++)
		addedge(i+2*n+f,tt);
	int ans=max_flow(s,tt);
	printf("%d\n",ans);
	return 0;
}
