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
#define MAXN 1005
#define MAXM 1000005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool g[MAXN][MAXN],vis[MAXN];
int head[MAXN],match[MAXN];

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

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				g[i][j]=false;
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			g[u][v]=1;
		}
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(g[i][j]==false&&g[i][k]==true&&g[k][j]==true)
						g[i][j]=true;
		fill(head,head+2*n,-1);em=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(g[i][j]==true&&i!=j)
					addedge(i*2,j*2+1);
		int cnt=0;
		fill(match,match+2*n,-1);
		for(int i=0;i<2*n;i+=2){
			fill(vis,vis+2*n,false);
			if(dfs(i))
				cnt++;
		}
		printf("%d\n",n-cnt);
	}
	return 0;
}
