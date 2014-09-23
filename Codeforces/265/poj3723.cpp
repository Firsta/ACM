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
#define MAXV 20005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct edge{
	int from,to,w;
};
vector<edge> edges;

bool cmp(const edge &a,const edge &b){
	return a.w>b.w;
}

int fa[MAXV];

int find(int x){
	if(fa[x]==x)
		return fa[x];
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,r;
		scanf("%d%d%d",&n,&m,&r);
		for(int i=0;i<n+m;i++)
			fa[i]=i;
		edges.clear();
		while(r--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			edge tmp;
			tmp.from=u;tmp.to=n+v;tmp.w=w;
			edges.push_back(tmp);
		}
		sort(edges.begin(),edges.end(),cmp);
//		for(int i=0;i<edges.size();i++)
//			cout<<edges[i].from<<' '<<edges[i].to<<' '<<edges[i].w<<endl;
		int ans=0;
		for(int i=0;i<edges.size();i++){
			int u=edges[i].from;
			int v=edges[i].to;
			int x=find(u),y=find(v);
			if(x!=y){
				fa[x]=y;
				ans+=edges[i].w;
//				cout<<ans<<endl;
			}
		}
		ans=10000*(n+m)-ans;
		printf("%d\n",ans);
	}
	return 0;
}
