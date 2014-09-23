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

const int MAXN =5005;

ll p[MAXN],dp[MAXN][MAXN],mark[MAXN];

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
		scanf("%I64d",&p[i]);
	ll sum=0;
	for(int i=0;i<=m-1;i++)
		sum+=p[i];
	mark[m-1]=sum;
	for(int i=m;i<n;i++){
		sum-=p[i-m];
		sum+=p[i];
		mark[i]=sum;
	}
	for(int i=0;i<n;i++)
		for(int j=1;j<=k;j++){
			dp[i+1][j]=0;
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(i-m+1>=0)
				dp[i+1][j]=max(dp[i+1][j],dp[i+1-m][j-1]+mark[i]);
		}
	ll ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,dp[i][k]);
	printf("%I64d",ans);
	return 0;
}
