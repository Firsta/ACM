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
#define MAXN 55
#define MAXD 10005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

double dp[MAXN][MAXD][2],ans[MAXN];
vector<int> G[MAXN];

int no;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,d;
		scanf("%d%d%d",&n,&m,&d);
		for(int i=0;i<n;i++)
			G[i].clear();
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u-1].push_back(v-1);
			G[v-1].push_back(u-1);
		}
		fill(ans,ans+n,0.0);
		double base=1.0/(1.0*n);
		for(int i=0;i<n;i++){
			no=i;
			for(int j=0;j<n;j++)
				for(int k=0;k<=d;k++)
					dp[j][k][0]=dp[j][k][1]=0.0;
			for(int j=0;j<n;j++){
				if(j!=no)
					dp[j][0][0]=base;
				else{
					dp[j][0][1]=base;
					ans[no]+=base;
				}
			}
			for(int j=1;j<=d;j++){
				for(int u=0;u<n;u++){
					for(int k=0;k<G[u].size();k++){
						int v=G[u][k];
						int num=G[v].size();
						if(u==no){
							dp[u][j][1]+=dp[v][j-1][0]/(1.0*num);
							ans[no]+=dp[v][j-1][0]/(1.0*num);
							dp[u][j][0]=0;
						}
						else{
							dp[u][j][1]+=dp[v][j-1][1]/(1.0*num);
							dp[u][j][0]+=dp[v][j-1][0]/(1.0*num);
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++)
			printf("%.10f\n",1.0-ans[i]);
	}
	return 0;
}
