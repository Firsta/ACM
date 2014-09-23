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
#define MAXV 200005
#define MAXE 500000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXV],vis[MAXV],mark[MAXV],ha[MAXV],sx[MAXV],hh[MAXV];
int n,m,k,l,be;

struct edge{
	int to,next;
}edges[MAXE];
int em;

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
	edges[em].next=head[v];
	edges[em].to=u;
	head[v]=em++;
}

bool bfs(){
	int cnt=2;
	bool flag=false;
	if(k==1)
		flag=true;
	queue<int> q;
	q.push(be);
	memset(vis,0,sizeof(vis));
	memset(ha,0,sizeof(ha));
	vis[be]=1;
	while(1){
		while(!q.empty()){
			int now=q.front();q.pop();
			for(int e=head[now];e!=-1;e=edges[e].next){
				int v=edges[e].to;
				if(!vis[v]&&mark[v]>cnt)
					ha[mark[v]]=1;
				if(!vis[v]&&(!mark[v]||mark[v]==cnt)){
					vis[v]=1;
					if(mark[v]==cnt){
						if(cnt==l&&flag==false){
							flag=true;
						}
						cnt++;
					}
					q.push(v);
				}
			}
		}
		if(vis[sx[cnt-1]]&&ha[cnt]==1){
			ha[cnt]=0;
			vis[sx[cnt]]=1;
			q.push(sx[cnt]);
			if(cnt==l&&flag==false)
				flag=true;
			cnt++;
			continue;
		}
		break;
	}
	if(flag){
		for(int i=1;i<=n;i++)
			if(!vis[i])
				return false;
		return true;
	}else
		return false;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(hh,false,sizeof(hh));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;i++){
			int tmp;
			scanf("%d",&tmp);
			hh[tmp]=1;
		}
		em=0;
		memset(head,-1,sizeof(head));
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		scanf("%d",&l);
		memset(mark,0,sizeof(mark));
		for(int i=1;i<=l;i++){
			scanf("%d",&sx[i]);
			if(i==1)
				be=sx[i];
			mark[sx[i]]=i;
		}
		if(l<k)
			printf("No\n");
		else if(bfs())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
