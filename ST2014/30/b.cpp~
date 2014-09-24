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
#define MAXN 100005
#define MAXM 1000005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXN],son[MAXN],cc[MAXN],vis[MAXN];

struct edge{
	int to,next;
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

int mincnt,n;
ll l,r;

void dfs(int x){
	vis[x]=true;
	son[x]=0;
	int cnt=0;
	for(int e=head[x];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!vis[v]){
			dfs(v);
			son[x]+=(son[v]+1);
			cnt=max(cnt,son[v]+1);
		}
	}
	cnt=max(cnt,n-son[x]-1);
	cc[x]=cnt;
	if(cnt<mincnt)
		mincnt=cnt;
}

ll sum;
void dfs2(int x,int len){
	vis[x]=true;
	sum+=len;
	for(int e=head[x];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!vis[v])
			dfs2(v,len+1);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d%lld%lld",&n,&l,&r);
		memset(head,-1,sizeof(head));
		memset(cc,0,sizeof(cc));
		memset(son,0,sizeof(son));
		for(int i=0;i<n-1;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(x-1,y-1);
		}
		memset(vis,0,sizeof(vis));
		mincnt=n;
		dfs(0);
		vector<int> ans;
		for(int i=0;i<n;i++)
			if(mincnt==cc[i])
				ans.push_back(i);
		sum=0;
		memset(vis,0,sizeof(vis));
		dfs2(ans[0],0);
		printf("%lld\n",sum*l*l*r);
		sort(ans.begin(),ans.end());
		printf("%d",ans[0]+1);
		for(int i=1;i<ans.size();i++)
			printf(" %d",ans[i]+1);
		if(cas!=t)
			printf("\n\n");
	}
	return 0;
}
