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
#define MAXN 10005
#define MAXM 100000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool mark[MAXN];
int head[MAXN],S[MAXN];
int c;

struct edge{
	int to,next;
}edges[MAXM];
int em;

void addedge(int u,int v){
	edges[em].next=head[u];
	edges[em].to=v;
	head[u]=em++;
}

bool dfs(int u){
	if(mark[u^1])
		return false;
	if(mark[u])
		return true;
	mark[u]=true;
	S[c++]=u;
	for(int e=head[u];e!=-1;e=edges[e].next){
		if(!dfs(edges[e].to))
			return false;
	}
	return true;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		em=0;
		memset(head,-1,sizeof(head));
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a<0){
				if(b>0){
					addedge(2*(-a)+1,2*b+1);
					addedge(2*b,2*(-a));
				}
				else if(b<0){
					addedge(2*(-a)+1,2*(-b));
					addedge(2*(-b)+1,2*(-a));
				}
			}else if(a>0){
				if(b>0){
					addedge(2*a,2*b+1);
					addedge(2*b,2*a+1);
				}else if(b<0){
					addedge(2*a,2*(-b));
					addedge(2*(-b)+1,2*a+1);
				}
			}
		}
		memset(mark,false,sizeof(mark));
		c=0;
		if(dfs(3)){
			bool flag=true;
			for(int i=4;i<2*(n+1);i+=2)
				if(!mark[i]&&!mark[i+1]){
					c=0;
					if(!dfs(i)){
						while(c>0)
							mark[S[--c]]=false;
						if(!dfs(i+1)){
							flag=false;
							break;
						}
					}
				}
			if(!flag)
				printf("no\n");
			else
				printf("yes\n");
		}
		else
			printf("no\n");
	}
	return 0;
}
