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
#include<fstream>
#include<sstream>
#include<string>

typedef long long ll;
using namespace std;

int tri[355][355];
int dp[355][355];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			scanf("%d",&tri[i][j]);
	for(int i=0;i<n;i++)
		dp[n-1][i]=tri[n-1][i];
	for(int i=n-2;i>=0;i--)
		for(int j=0;j<=i;j++)
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+tri[i][j];
	printf("%d\n",dp[0][0]);
	return 0;
}
