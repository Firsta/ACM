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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int vis[505],head[505];

struct edge{
	int to,next;
}edges[250005];
int em;
int vis2[250005];

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

int ee,vv;
void dfs(int x){
	vv++;
	vis[x]=1;
	for(int e=head[x];e!=-1;e=edges[e].next){
		if(!vis2[e]){
			ee++;
			vis2[e]=1;
		}
	}
	for(int e=head[x];e!=-1;e=edges[e].next){
		if(!vis[edges[e].to])
			dfs(edges[e].to);
	}
}

int main(){
	int n,m,cas=0;
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		cas++;
		fill(head,head+n+1,-1);
		em=0;
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		int ans=0;
		fill(vis,vis+n+1,0);
		fill(vis2,vis2+em+1,0);
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vv=0,ee=0;
				dfs(i);
//				cout<<vv<<' '<<ee<<endl;
				ee/=2;
				if(ee==vv-1)
					ans++;
			}
		}
		printf("Case %d: ",cas);
		if(ans==1)
			printf("There is one tree.\n");
		else if(ans==0)
			printf("No trees.\n");
		else
			printf("A forest of %d trees.\n",ans);
	}
	return 0;
}
