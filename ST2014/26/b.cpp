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

ll dp[1005][1005];
ll sum[1005][1005];
ll grid[1005][1005];

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++)
			for(int j=0;j<i+1;j++)
				scanf("%lld",&grid[i][j]);
		for(int j=0;j<n;j++){
			sum[j][j]=grid[j][j];
			for(int i=j+1;i<n;i++)
				sum[i][j]=sum[i-1][j]+grid[i][j];
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			dp[i][0]=sum[i][0];
		ll maxx;
		for(int j=1;j<n;j++){
			maxx=dp[n-1][j-1];
			for(int i=n-1;i>=j;i--){
				maxx=max(maxx,dp[i-1][j-1]);
				dp[i][j]=sum[i][j]+maxx;
			}
		}
		ll ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<i+1;j++)
				ans=max(ans,dp[i][j]);
		if(ans<0)
			ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}
