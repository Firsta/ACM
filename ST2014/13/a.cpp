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
#define MAXN 50
#define MAXM 2500

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int head[MAXN],head2[MAXN],hh[MAXN];
bool vis[MAXN];

struct edge{
	int next,to,w;
}edges[MAXM],edges2[MAXM];

int em,em2,n;
int hash[MAXN];

void addedge(int u,int v,int w){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].w=w;
	head[u]=em++;
}

void addedge2(int u,int v,int w){
	edges2[em2].next=head2[u];
	edges2[em2].to=v;
	edges2[em2].w=w;
	head2[u]=em2++;
}

void dfs(int x,vector<int> htmp){
	vis[x]=true;
	bool find=false;
	for(int e=head2[x];e!=-1;e=edges2[e].next){
		int v=edges2[e].to;
		if(!vis[v])
			htmp[v]+=edges2[e].w;
	}
	for(int e=head[x];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!vis[v])
			htmp[v]-=edges[e].w;
	}
	for(int i=0;i<n;i++)
		if(htmp[i]<0&&!vis[i]){
			find=true;
			dfs(i,htmp);
		}
	if(find==false){
		for(int i=0;i<n;i++)
			if(htmp[i]>=0&&!hash[i])
				hash[i]=1;
	}
	vis[x]=false;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(head,-1,sizeof(head));
		memset(head2,-1,sizeof(head2));
		memset(vis,0,sizeof(vis));
		memset(hh,0,sizeof(hh));
		memset(hash,0,sizeof(hash));
		em=em2=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				int tmp;
				scanf("%d",&tmp);
				if(i>j){
					if(tmp>0){
						addedge(i,j,tmp);
						hh[j]+=tmp;
						hh[i]-=tmp;
						addedge2(j,i,tmp);
					}
					else if(tmp<0){
						addedge(j,i,-tmp);
						hh[i]+=(-tmp);
						hh[j]-=(-tmp);
						addedge2(i,j,-tmp);
					}
				}
			}
		vector<int> hav;
		for(int i=0;i<n;i++){
			hav.push_back(hh[i]);
		}
		for(int i=0;i<n;i++){
			if(hav[i]<0){
				dfs(i,hav);
			}
		}
		int cnt=0;
		int ans[MAXN];
		for(int i=0;i<n;i++)
			if(hash[i])
				ans[cnt++]=i;;
		if(cnt==0)
			printf("0\n");
		else{
			sort(ans,ans+cnt);
			printf("%d",ans[0]+1);
			for(int i=1;i<cnt;i++)
				printf(" %d",ans[i]+1);
			printf("\n");
		}
	}
	return 0;
}
