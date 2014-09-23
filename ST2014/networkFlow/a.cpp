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
#define MAX_V 1005
#define MAX_E 250005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct edge{
	int to,next;
}edges[MAX_E];
int em;

int head[MAX_V],match[MAX_V],vis[MAX_V];

void addedge(int u,int v){
	edges[em].to=v;
	edges[em].next=head[u];
	head[u]=em++;
}

bool dfs(int u){
	vis[u]=1;
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		int w=match[v];
		if(w<0||!vis[w]&&dfs(w)){
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	fill(head,head+2*n,-1);
	while(k--){
		int r,c;
		scanf("%d%d",&r,&c);
		addedge(r-1,c+n-1);
		addedge(c+n-1,r-1);
	}
	int ans=0;
	fill(match,match+2*n,-1);
	for(int i=0;i<2*n;i++){
		if(match[i]<0){
			fill(vis,vis+2*n,0);
			if(dfs(i))
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
