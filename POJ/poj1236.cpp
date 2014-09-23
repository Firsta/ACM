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
#define MAXN 105
#define MAXM 10005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int dfn[MAXN],low[MAXN],head[MAXN],belong[MAXN],in[MAXN],out[MAXN],ind,cnt;
bool ins[MAXN];

struct edge{
	int to,next;
}edges[MAXM];
int em;

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

stack<int> s;

void Tarjan(int u){
	low[u]=dfn[u]=++ind;
	ins[u]=true;
	s.push(u);
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(ins[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int tmp;
		cnt++;
		do{
			tmp=s.top();
			s.pop();
			ins[tmp]=false;
			belong[tmp]=cnt;
		}while(tmp!=u);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	fill(head,head+n,-1);
	for(int u=0;u<n;u++){
		int v;
		while(scanf("%d",&v)&&v)
			addedge(u,v-1);
	}
	for(int i=0;i<n;i++)
		if(!dfn[i])
			Tarjan(i);
	for(int u=0;u<n;u++){
		for(int e=head[u];e!=-1;e=edges[e].next){
			int v=edges[e].to;
			if(belong[v]!=belong[u]){
				in[belong[v]]++;
				out[belong[u]]++;
			}
		}
	}
	int ans1=0,ans2=0;
	if(cnt==1){
		printf("1\n0");
		return 0;
	}
	for(int i=1;i<=cnt;i++){
		if(in[i]==0)
			ans1++;
		if(out[i]==0)
			ans2++;
	}
	printf("%d\n%d",ans1,max(ans1,ans2));
	return 0;
}
