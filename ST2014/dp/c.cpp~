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

int dp[1001][31];

int main(){
	int t,w,tmp;
	scanf("%d%d",&t,&w);
	for(int i=1;i<=t;i++){
		scanf("%d",&tmp);
		if(tmp==2){
			for(int j=0;j<=w;j++){
				if(j%2==0){
					dp[i][j]=dp[i-1][j];
					if(j>0)
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
					if(j>1)
						dp[i][j]=max(dp[i][j],dp[i-1][j-2]+1);
				}else{
					dp[i][j]=dp[i-1][j]+1;
					if(j>0)
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
				}
			}
		}else{
			for(int j=0;j<=w;j++){
				if(j%2==0){
					dp[i][j]=dp[i-1][j]+1;
					if(j>0)
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
				}else{
					dp[i][j]=dp[i-1][j];
					if(j>0)
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
					if(j>1)
						dp[i][j]=max(dp[i][j],dp[i-1][j-2]+1);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=w;i++)
		ans=max(ans,dp[t][i]);
	printf("%d",ans);
	return 0;
}
