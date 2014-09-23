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
#define MAXN 205

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int grid[MAXN][MAXN],dfn[MAXN],low[MAXN],belong[MAXN],head[MAXN],ins[MAXN];
int ind,em,cnt,vis[MAXN][MAXN],cn[MAXN],ce[MAXN];
stack<int> s;

struct edge{
	int to,next;
}edges[MAXN*MAXN];

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

void tarjan(int x){
	low[x]=dfn[x]=++ind;
	ins[x]=1;
	s.push(x);
	for(int e=head[x];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}else if(ins[v])
			low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]){
		int t;
		cnt++;
		do{
			t=s.top();
			s.pop();
			ins[t]=0;
			belong[t]=cnt;
		}while(t!=x);
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<=n;i++){
			belong[i]=dfn[i]=low[i]=ins[i]=0;
			head[i]=-1;
		}
		em=ind=cnt=0;
		int sum=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				int tmp;
				scanf("%d",&tmp);
				if(i!=j&&tmp==1){
					addedge(i,j);
				}
			}
		for(int i=1;i<=n;i++){
			if(!dfn[i])
				tarjan(i);
		}
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++){
				grid[i][j]=0;
				vis[i][j]=0;
			}
		for(int i=0;i<=cnt;i++)
			cn[i]=0;
		for(int i=1;i<=n;i++){
			cn[belong[i]]++;
			for(int e=head[i];e!=-1;e=edges[e].next){
				int v=edges[e].to;
				if(belong[i]!=belong[v])
					grid[belong[i]][belong[v]]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=cnt;i++)
			if(cn[i]>1)
				ans+=cn[i];
		for(int k=1;k<=cnt;k++)
			for(int i=1;i<=cnt;i++)
				for(int j=1;j<=cnt;j++)
					if(grid[i][k]&&grid[k][j]&&grid[i][j]&&!vis[i][j]){
						vis[i][j]=1;
					}
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				if(grid[i][j]&&!vis[i][j])
					ans++;
		printf("%d\n",ans);
	}
	return 0;
}
