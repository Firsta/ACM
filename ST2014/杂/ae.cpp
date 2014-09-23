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
#define MAXM 6000
#define MAXN 1000
#define INF 10000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n,s,t;

int head[MAXN],ds[MAXN],dt[MAXN],pret[MAXN],pres[MAXN];
bool vis[MAXN];

struct edge{
	int from,to,w,next;
}edges[MAXM],ce[MAXM];
int em;

void addedge(int u,int v,int w){
	edges[em].from=u;
	edges[em].to=v;
	edges[em].w=w;
	edges[em].next=head[u];
	head[u]=em++;
	edges[em].from=v;
	edges[em].to=u;
	edges[em].w=w;
	edges[em].next=head[v];
	head[v]=em++;
}

struct node{
	int v,d;
	bool operator < (const node &a) const{
		return d>a.d;
	}
};

int main(){
	int id=0;
	while(~scanf("%d%d%d",&n,&s,&t)){
		if(id++)
			printf("\n");
		int m,k;
		em=0;
		memset(head,-1,sizeof(head));
		scanf("%d",&m);
		while(m--){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,z);
		}
		scanf("%d",&k);
		for(int i=0;i<k;i++)
			scanf("%d%d%d",&ce[i].from,&ce[i].to,&ce[i].w);
		priority_queue<node> pque;
		pque.push((node){s,0});
		fill(ds,ds+n+1,INF);
		fill(pres,pres+n+1,-1);
		fill(vis,vis+n+1,false);
		ds[s]=0;
		while(!pque.empty()){
			node now=pque.top();
			pque.pop();
			if(vis[now.v])
				continue;
			vis[now.v]=true;
			for(int e=head[now.v];e!=-1;e=edges[e].next){
				int v=edges[e].to;
				if(ds[v]>ds[now.v]+edges[e].w){
					ds[v]=ds[now.v]+edges[e].w;
					pres[v]=now.v;
					pque.push((node){v,ds[v]});
				}
			}
		}
	//	cout<<ds[t]<<'!'<<endl;
		pque.push((node){t,0});
		fill(dt,dt+n+1,INF);
		fill(pret,pret+n+1,-1);
		fill(vis,vis+n+1,false);
		dt[t]=0;
		while(!pque.empty()){
			node now=pque.top();
			pque.pop();
			if(vis[now.v])
				continue;
			vis[now.v]=true;
			for(int e=head[now.v];e!=-1;e=edges[e].next){
				int v=edges[e].to;
				if(dt[v]>dt[now.v]+edges[e].w){
					dt[v]=dt[now.v]+edges[e].w;
					pret[v]=now.v;
					pque.push((node){v,dt[v]});
				}
			}
		}
	//	cout<<dt[s]<<'!'<<endl;
		int ans=ds[t];
		int tu=0,tv=0;
		for(int i=0;i<k;i++){
			if(ans>ds[ce[i].from]+dt[ce[i].to]+ce[i].w){
				ans=ds[ce[i].from]+dt[ce[i].to]+ce[i].w;
				tu=ce[i].from;
				tv=ce[i].to;
			}
			if(ans>ds[ce[i].to]+dt[ce[i].from]+ce[i].w){
				ans=ds[ce[i].to]+dt[ce[i].from]+ce[i].w;
				tu=ce[i].to;
				tv=ce[i].from;
			}
		}
		if(tu==0&&tv==0){
			int tmp=s;
			printf("%d",s);
			while(pret[tmp]!=-1){
				printf(" %d",pret[tmp]);
				tmp=pret[tmp];
			}
			printf("\n");
		}else{
			stack<int> roate;
			roate.push(tu);
			int tmp=tu;
			while(pres[tmp]!=-1){
				roate.push(pres[tmp]);
				tmp=pres[tmp];
			}
			while(!roate.empty()){
				printf("%d ",roate.top());
				roate.pop();
			}
			printf("%d",tv);
			tmp=tv;
			while(pret[tmp]!=-1){
				printf(" %d",pret[tmp]);
				tmp=pret[tmp];
			}
			printf("\n");
		}
		if(tu==0&&tv==0)
			printf("Ticket Not Used\n");
		else{
			printf("%d\n",tu);
		}
		printf("%d\n",ans);
	}
	return 0;
}
