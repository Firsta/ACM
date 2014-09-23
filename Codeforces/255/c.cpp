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
using namespace std;

int dp[100005][2];
ll a[100005];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])
			dp[i][0]=dp[i-1][0]+1;
		else if(a[i]<=a[i-1])
			dp[i][0]=1;
	}
	dp[n][1]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]<a[i+1])
			dp[i][1]=dp[i+1][1]+1;
		else
			dp[i][1]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]-a[i-1]>1)
			ans=max(ans,dp[i-1][0]+dp[i+1][1]+1);
		ans=max(ans,dp[i-1][0]+1);
		ans=max(ans,dp[i+1][1]+1);
	}
	cout<<ans<<endl;
	return 0;
}
