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
#define MAXN 305
#define INF 100000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int d[MAXN][MAXN],a[MAXN],ind;
int n,m;

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			d[i][j]=INF;
		d[i][i]=0;
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		init();
		while(m--){
			int cnt;ind=0;
			scanf("%d",&cnt);
			for(int i=0;i<cnt;i++){
				int tmp;
				scanf("%d",&tmp);
				a[ind++]=tmp;
			}
			for(int i=0;i<ind;i++){
				for(int j=i+1;j<ind;j++)
					d[a[i]][a[j]]=d[a[j]][a[i]]=1;
			}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		int ans=INT_MAX;
		for(int i=1;i<=n;i++){
			int tmp=0;
			for(int j=1;j<=n;j++)
				tmp+=100*d[i][j];
			ans=min(ans,tmp/(n-1));
		}
		printf("%d\n",ans);
	}
	return 0;
}
