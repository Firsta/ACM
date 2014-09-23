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
#define MAX_V 2505
#define MAX_E 25000

typedef int ll;
typedef unsigned long long ull;
using namespace std;

int level[MAX_V],iter[MAX_V],head[MAX_V];

struct edge{
	int to,next,rev,cap;
}edges[MAX_E];
int em,V;

void addedge(int u,int v,ll cap){
	edges[em].to=v;
	edges[em].next=head[u];
	edges[em].rev=em+1;
	edges[em].cap=cap;
	head[u]=em++;
	edges[em].to=u;
	edges[em].next=head[v];
	edges[em].cap=0;
	edges[em].rev=em-1;
	head[v]=em++;
}

void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> q;
	level[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int e=head[u];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(edges[e].cap>0&&level[v]<0){
				level[v]=level[u]+1;
				q.push(v);
			}
		}
	}
}

int dfs(int s,int t,int f){
	if(s==t)
		return f;
	for(int &e=iter[s];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(edges[e].cap>0&&level[s]<level[v]){
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

int mai_flow(int s,int t){
	int flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)
			return flow;
		for(int i=0;i<V;i++)
			iter[i]=head[i];
		int f;
		while((f=dfs(s,t,INF))>0)
			flow+=f;
	}
}

int main(){
	int n,m;
	while(~scanf("%d",&n)){
		m=n;
		int s=m*n,t=m*n+1;
		int ans=0;
		em=0;V=m*n+2;
		memset(head,-1,sizeof(head));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				int tmp;
				scanf("%d",&tmp);
				ans+=tmp;
				if((i+j)%2==0){
					addedge(s,i*n+j,tmp);
					if(i-1>=0)
						addedge(i*n+j,(i-1)*n+j,INF);
					if(i+1<m)
						addedge(i*n+j,(i+1)*n+j,INF);
					if(j-1>=0)
						addedge(i*n+j,i*n+j-1,INF);
					if(j+1<n)
						addedge(i*n+j,i*n+j+1,INF);
				}else
					addedge(i*n+j,t,tmp);
			}
		ans=ans-mai_flow(s,t);
		printf("%d\n",ans);
	}
	return 0;
}
