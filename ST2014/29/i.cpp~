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
#define MAX_V 9000
#define MAX_E 300000
#define INF 100000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int outm[400],outn[400],head[MAX_V];

int level[MAX_V],iter[MAX_V];
int V;

struct edge{
	int to,cap,next,rev,ind;
}edges[MAX_E];
int em;

void addedge(int u,int v,int cap,int ind){
	edges[em].to=v;
	edges[em].next=head[u];
	edges[em].rev=em+1;
	edges[em].cap=cap;
	edges[em].ind=ind;
	head[u]=em++;
	edges[em].to=u;
	edges[em].next=head[v];
	edges[em].cap=0;
	edges[em].rev=em-1;
	edges[em].ind=-1;
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

int max_flow(int s,int t){
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
	int m,n,p;
	scanf("%d%d%d",&m,&n,&p);
	memset(head,-1,sizeof(head));
	V=m+n+3;
	for(int i=1;i<=p;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		outm[u]++;
		outn[v]++;
		addedge(u,m+v,1,i);
	}
	bool flag=true;
	for(int i=1;i<=m;i++){
		if(outm[i]<2){
			flag=false;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(outn[i]<2){
			flag=false;
			break;
		}
	}
	if(!flag){
		printf("-1\n");
		return 0;
	}
	int s=0,t=m+n+1;
	for(int i=1;i<=m;i++)
		addedge(s,i,outm[i]-2,-1);
	for(int i=1;i<=n;i++)
		addedge(i+m,t,outn[i]-2,-1);
	printf("%d\n",p-max_flow(s,t));
	vector<int> ans;
	for(int i=0;i<em;i++)
		if(edges[i].ind!=-1&&edges[i].cap==1)
			ans.push_back(edges[i].ind);
	sort(ans.begin(),ans.end());
	printf("%d",ans[0]);
	for(int i=1;i<ans.size();i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
