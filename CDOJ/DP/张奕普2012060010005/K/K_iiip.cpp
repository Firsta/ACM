#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define INF 1000000

typedef long long ll;
using namespace std;

int dp[205][205];
int a[205];

int sum(int l,int r)
{
	int ans=0;
	for(int i=l;i<=r;i++)
		ans+=a[i];
	return ans;
}

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=n;i<2*n;i++)
			a[i]=a[i-n];
		for(int i=0;i<2*n;i++)
			for(int j=0;j<2*n;j++)
				dp[i][j]=INF;
		for(int i=0;i<2*n;i++)
			dp[i][i]=0;
		for(int d=1;d<n;d++)
			for(int l=0;l+d<2*n;l++)
				for(int k=l;k<l+d;k++)
					dp[l][l+d]=min(dp[l][l+d],dp[l][k]+dp[k+1][l+d]+sum(l,l+d));
		int ans=INF;
		for(int i=0;i+n-1<2*n;i++)
			if(ans>dp[i][i+n-1])
				ans=dp[i][i+n-1];
/*		for(int i=0;i<2*n;i++)
		{
			for(int j=0;j<2*n;j++)
				cout<<dp[i][j]<<' ';
			cout<<endl;
		}*/
		cout<<ans<<endl;
	}
	return 0;
}
