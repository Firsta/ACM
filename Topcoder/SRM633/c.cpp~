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

int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int head[505],l[505],vis[505],g[505];
bool flag;
int no;

struct edge{
	int to,next,gcd,lcm;
}edges[505*505];
int em;

void addedge(int u,int v,int g,int l){
	edges[em].next=head[u];
	edges[em].to=v;
	edges[em].gcd=g;
	edges[em].lcm=l;
	head[u]=em++;
}

void dfs(int u){
	vis[u]=true;
	for(int e=head[u];e!=-1;e=edges[e].next){
		int v=edges[e].to;
		if(!vis[v]){
			int tgcd=gcd(g[u],edges[e].gcd);
			if(edges[e].lcm*l[u]%tgcd!=0){
				flag=false;
				return;
			}
			int tlcm=edges[e].lcm*l[u]/tgcd;
			g[v]=tgcd;l[v]=tlcm;
			dfs(v);
		}else if(v==no){
			if(l[u]!=edges[e].lcm||g[u]!=edges[e].gcd){
				flag=false;
				cout<<1<<endl;
				return;
			}
		}
	}
	return;
}

class GCDLCMEasy{
	public:
		string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L){
			memset(head,-1,sizeof(head));
			for(int i=0;i<n;i++)
				addedge(A[i],B[i],G[i],L[i]);
			for(int i=0;i<n;i++){
				no=i;
				memset(vis,0,sizeof(vis));
				memset(g,0,sizeof(g));
				memset(l,0,sizeof(l));
				g[i]=0;l[i]=1;
				flag=true;
				dfs(i);
				if(!flag){
					cout<<i<<endl;
					return "No solution";
				}
			}
			return "Solution exists";
		}
};
