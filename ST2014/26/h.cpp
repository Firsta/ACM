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
#define MAXN 20005
#define MAXM 300005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXN],par[MAXN],pre[MAXN],low[MAXN];

int find(int x){
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}

struct edge{
	int next,to;
}edges[MAXM];
int em;

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	head[v]=em++;
}

int ind=0;
int dfs(int u,int fa){
	int lowu=pre[u]=++ind;
	int child=0;
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!pre[v]){
			child++;
			int lowv=dfs(v,u);
			lowu=min(lowv,lowu);
			if(lowv>pre[u]){
				int a=find(v),b=find(u);
				if(b!=a)
					par[b]=a;
			}
		}else if(pre[v]<pre[u]&&v!=fa)
			lowu=min(lowu,pre[v]);
	}
	return lowu;
}

int main(){
	int r,c,q;
	while(~scanf("%d%d%d",&r,&c,&q)&&(r||c||q)){
		for(int i=0;i<=r;i++){
			head[i]=-1;
			par[i]=i;
			pre[i]=low[i]=0;
		}
		em=ind=0;
		while(c--){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		for(int i=1;i<=r;i++){
			if(!pre[i])
				dfs(i,-1);
		}
		while(q--){
			int u,v;
			scanf("%d%d",&u,&v);
			int x=find(u),y=find(v);
			if(x!=y)
				printf("N\n");
			else
				printf("Y\n");
		}
		printf("-\n");
	}
	return 0;
}
