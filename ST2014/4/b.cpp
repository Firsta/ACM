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
#define MAXM 250000
#define MAXN 505

typedef long long ll;
using namespace std;

int em,f[MAXN];

int find(int x){
	return f[x]==x?f[x]:f[x]=find(f[x]);
}

struct edge{
	int from,to,w;
}edges[MAXM];

void addedge(int u,int v,int w){
	edges[em].from=u;
	edges[em].to=v;
	edges[em++].w=w;
}

bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,e;
		em=0;
		scanf("%d%d",&n,&e);
		for(int i=0;i<n;i++)
			f[i]=i;
		for(int i=0;i<e;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		sort(edges,edges+e,cmp);
		int ans=0;
		for(int i=0;i<e;i++){
			int x=find(edges[i].from);
			int y=find(edges[i].to);
			if(x!=y){
				ans+=edges[i].w;
				f[x]=y;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
