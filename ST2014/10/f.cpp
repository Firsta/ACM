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
#define MAXN 1005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int cnt[MAXN][MAXN],dp[MAXN];

int main(){
	int n,cas=0;
	while(~scanf("%d",&n)&&n){
		cas++;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				cnt[i][j]=0;
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a+b>=n)
				continue;
			cnt[a+1][n-b]++;
		}
		for(int i=0;i<=n;i++)
			dp[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				dp[i]=max(dp[i],dp[j]+min(i-j,cnt[j+1][i]));
			}
		}
//		for(int i=0;i<=n;i++)
//			cout<<dp[i]<<' ';
//		cout<<endl;
		printf("Case %d: %d\n",cas,n-dp[n]);
	}
	return 0;
}
