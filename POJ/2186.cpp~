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

int dfn[MAXN],low[MAXN],head[MAXN],ins[MAXN],out[MAXN],belong[MAXN];
stack<int> st;
int em,ind,cnt;

struct edge{
	int to,next;
}edges[MAXM];

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

void tarjan(int u){
	dfn[u]=low[u]=++ind;
	ins[u]=1;
	st.push(u);
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(ins[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		cnt++;
		int t;
		do{
			t=st.top();
			ins[t]=0;
			st.pop();
			belong[t]=cnt;
		}while(t!=u);
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])
			tarjan(i);
	}
	for(int i=1;i<=n;i++){
		for(int e=head[i];e!=-1;e=edges[e].next){
			if(belong[edges[e].to]!=belong[i]){
				out[belong[i]]++;
			}
		}
	}
	int scc=0;int tmp=0;
	for(int i=1;i<=cnt;i++){
		if(out[i]==0){
			scc=i;
			tmp++;
		}
	}
	if(tmp>1||tmp==0){
		printf("0\n");
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(belong[i]==scc){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
