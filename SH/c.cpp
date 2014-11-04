#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define MAXN 200005
#define lc (o << 1)
#define rc ((o << 1)|1)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXN],dep[MAXN],id[MAXN],fa[MAXN],top[MAXN],son[MAXN],siz[MAXN],ee[MAXN][2];
bool chn[(MAXN<<2)],che[(MAXN<<2)];
char str[4];
int n,m,em,ind;

struct edge{
	int next,to;
} edges[2*MAXN+5];

inline void swap(int &a, int &b) {
    a += b;
    b = a-b;
    a -= b;
}

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

void dfs1(int u){
	siz[u]=1;son[u]=0;
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(v!=fa[u]){
			fa[v]=u;dep[v]=dep[u]+1;
			dfs1(v);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])
				son[u]=v;
		}
	}
}

void dfs2(int u,int tp){
	top[u]=tp;id[u]=++ind;
	if(son[u]!=0)
		dfs2(son[u],top[u]);
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(v!=son[u]&&v!=fa[u])
			dfs2(v,v);
	}
}

ll sumvn[(MAXN<<2)],addvn[(MAXN<<2)];

void maintainn(int o,int L,int R){
	sumvn[o]=0;
	if(R>L)
		sumvn[o]=sumvn[lc]+sumvn[rc];
	sumvn[o]+=addvn[o]*(ll)(R-L+1);
}

void updaten(int o,int L,int R,int l,int r,int v){
	if(l<=L&&r>=R)
		addvn[o]+=(ll)v;
	else{
		int M=L+((R-L) >> 1);
		if(l<=M)
			updaten(lc,L,M,l,r,v);
		if(r>M)
			updaten(rc,M+1,R,l,r,v);
	}
	maintainn(o,L,R);
}

ll queryn(int o,int L,int R,int p,ll add){
	if(L==R)
		return sumvn[o]+add*(ll)(R-L+1);
	else{
		int M=L+((R-L) >> 1);
		if(p<=M)
			return queryn(lc,L,M,p,add+addvn[o]);
		else
			return queryn(rc,M+1,R,p,add+addvn[o]);
	}
}

void changen(int x,int y,int val){
	while(top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]])
            swap(x,y);
		updaten(1,1,n,id[top[x]],id[x],val);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		swap(x,y);
	updaten(1,1,n,id[x],id[y],val);
}

ll sumve[(MAXN<<2)],addve[(MAXN<<2)];

void maintaine(int o,int L,int R){
	sumve[o]=0;
	if(R>L){
		sumve[o]=sumve[lc]+sumve[rc];
		che[o]=che[lc]|che[rc];
	}
	sumve[o]+=addve[o]*(ll)(R-L+1);
}

void updatee(int o,int L,int R,int l,int r,int v){
	if(l<=L&&r>=R){
		addve[o]+=(ll)v;
	}else{
		int M=L+((R-L) >> 1);
		if(l<=M)
			updatee(lc,L,M,l,r,v);
		if(r>M)
			updatee(rc,M+1,R,l,r,v);
	}
	maintaine(o,L,R);
}

ll querye(int o,int L,int R,int p,ll add){
	if(L==R)
		return sumve[o]+add*(ll)(R-L+1);
	else{
		int M=L+((R-L) >> 1);
		if(p<=M)
			return querye(lc,L,M,p,add+addve[o]);
		else
			return querye(rc,M+1,R,p,add+addve[o]);
	}
}

void changee(int x,int y,int val){
	cout<<1<<endl;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		updatee(1,1,n,id[top[x]],id[x],val);
//		cout<<id[top[x]]<<' '<<id[x]<<endl;
		x=fa[top[x]];
	}
	if(x==y)
		return;
	if(dep[x]>dep[y])
		swap(x,y);
	updatee(1,1,n,id[son[x]],id[y],val);
//	cout<<id[son[x]]<<' '<<id[y]<<endl;
}

void init(){
	scanf("%d%d",&n,&m);
	int root=((n+1)>>1), N = (n << 2);
	fa[root]=dep[root]=ind=em=0;
	fill(head,head+n+1,-1);
	fill(sumve,sumve+N+1,0);
	fill(sumvn,sumvn+N+1,0);
	fill(addve,addve+N+1,0);
	fill(addvn,addvn+N+1,0);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ee[i][0]=u;ee[i][1]=v;
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(root);
	dfs2(root,root);
	cout<<1<<endl;
}

void solve(){
	while(m--){
		int u,v,w;
		scanf("%s%d%d%d",str,&u,&v,&w);
		cout<<2<<endl;
		if(str[3]=='2'){
			changee(u,v,w);
			cout<<3<<endl;
		}
		else if(str[3]=='1')
			changen(u,v,w);
	}
	printf("%I64d",queryn(1,1,n,id[1],0));
	for(int i=2;i<=n;i++)
		printf(" %I64d",queryn(1,1,n,id[i],0));
	printf("\n");
	if(dep[ee[1][0]]>dep[ee[1][1]])
		printf("%I64d",querye(1,1,n,id[ee[1][0]],0));
	else
		printf("%I64d",querye(1,1,n,id[ee[1][1]],0));
	for(int i=2;i<n;i++){
		if(dep[ee[i][0]]>dep[ee[i][1]])
			printf("% I64d",querye(1,1,n,id[ee[i][0]],0));
		else
			printf("% I64d",querye(1,1,n,id[ee[i][1]],0));
	}
	printf("\n");
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		printf("Case #%d:\n",cas);
		init();
		solve();
	}
	return 0;
}

