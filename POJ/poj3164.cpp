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

int n,m,head[MAXN],reach[MAXN],vv[MAXN],pre[MAXN],id[MAXN];
double rb[MAXN],INF;

struct edge{
	int from,to,next;
	double w;
	edge(int from=0,int to=0,double w=0,int next=-1):from(from),to(to),w(w),next(next){

	}
}edges[MAXM];
int em;

void addedge(int u,int v,double w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	edges[em].from=u;
	head[u]=em++;
}

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){

	}
}p[MAXN];

double Distance(Point &a,Point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void dfs(int x){
	reach[x]=1;
	for(int e=head[x];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!reach[v])
			dfs(v);
	}
}

double ans;int V,E;
bool directed_MST(int root){
	ans=0;
	while(1){
		for(int i=0;i<V;i++)
			rb[i]=INF;
		for(int i=0;i<E;i++){
			int u=edges[i].from,v=edges[i].to;
			if(edges[i].w<rb[v]&&u!=v){
				pre[v]=u;
				rb[v]=edges[i].w;
			}
		}
		rb[root]=0;
		for(int i=0;i<V;i++)
			if(rb[i]==INF)
				return false;
		int cnt=0;
		fill(id,id+V,-1);
		fill(vv,vv+V,-1);
		for(int i=0;i<V;i++){
			ans+=rb[i];
			int tmp=i;
			while(vv[tmp]!=i&&id[tmp]==-1&&tmp!=root){
				vv[tmp]=i;
				tmp=pre[tmp];
			}
			if(tmp!=root&&id[tmp]==-1){
				for(int u=pre[tmp];u!=tmp;u=pre[u])
					id[u]=cnt;
				id[tmp]=cnt++;
			}
		}
		if(cnt==0)
			break;
		for(int i=0;i<V;i++)
			if(id[i]==-1)
				id[i]=cnt++;
		for(int i=0;i<E;i++){
			int u=edges[i].from,v=edges[i].to;
			edges[i].from=id[u];
			edges[i].to=id[v];
			if(id[u]!=id[v])
				edges[i].w-=rb[v];
		}
		V=cnt;
		root=id[root];
	}
	return true;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		INF=0.0;fill(head,head+n,-1);em=0;
		for(int i=0;i<m;i++){
			int u,v;
			double w;
			scanf("%d%d",&u,&v);
			w=Distance(p[u-1],p[v-1]);
			if(u!=v){
				INF=max(INF,w);
				addedge(u-1,v-1,w);
			}
		}
		INF+=1.0;E=em;V=n;
		if(!directed_MST(0))
			printf("poor snoopy");
		else
			printf("%.2f",ans);
		printf("\n");
	}
	return 0;
}
