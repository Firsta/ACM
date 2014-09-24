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
#define MAXN 305
#define MAXM 90005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n,m,head[MAXN],match[MAXN];
bool vis[MAXN];

struct edge{
	int to,next;
}edges[MAXM];
int em;

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

bool dfs(int u){
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!vis[v]){
			vis[v]=true;
			if(match[v]==-1||dfs(match[v])){
				match[v]=u;
				return true;
			}
		}
	}
	return false;
}

int count(){
	int res=0;
	fill(match,match+2*n,-1);
	for(int i=0;i<2*n;i+=2){
		fill(vis,vis+2*n,0);
		if(dfs(i))
			res++;
	}
	return res;
}

void init(){
	fill(head,head+2*n,-1);
	em=0;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			addedge(u*2,v*2+1);
		}
		printf("%d\n",n-count());
	}
	return 0;
}
