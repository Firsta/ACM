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
#define MAXN 10005
#define MAXM 50005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int cc[MAXN],head[MAXN],dfn[MAXN],ins[MAXN],low[MAXN],belong[MAXN];

struct edge{
	int to,next;
}edges[MAXM];
int em;

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

int ind,cnt;
stack<int> s;

void tarjan(int u){
	dfn[u]=low[u]=++ind;
	ins[u]=true;
	s.push(u);
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(ins[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		cnt++;
		int tmp;
		do{
			tmp=s.top();
			s.pop();
			belong[tmp]=cnt;
			cc[cnt]++;
			ins[tmp]=false;
		}while(u!=tmp);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fill(head,head+n,-1);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u-1,v-1);
	}
	for(int i=0;i<n;i++)
		if(!dfn[i])
			tarjan(i);
	int ans=0;
	for(int i=1;i<=cnt;i++)
		if(cc[i]==1)
			ans++;
	printf("%d",cnt-ans);
	return 0;
}
