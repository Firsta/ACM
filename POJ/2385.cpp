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

int dp[1005][35];
int a[1005];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int t,w;
	scanf("%d%d",&t,&w);
	for(int i=1;i<=t;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=t;i++)
		for(int j=0;j<=w;j++)
		{
			if(j%2==0)
			{
				if(a[i]==1)
					dp[i][j]=max(dp[i-1][j],max(dp[i][j-2],dp[i-1][j-1]))+1;
				else
					dp[i][j]=max(dp[i-1][j],max(dp[i][j-2],dp[i-1][j-1]));
			}
			else
			{
				if(a[i]==2)
					dp[i][j]=max(dp[i-1][j],max(dp[i][j-2],dp[i-1][j-1]))+1;
				else
					dp[i][j]=max(dp[i-1][j],max(dp[i][j-2],dp[i-1][j-1]));
			}
		}
	printf("%d\n",max(dp[t][w],dp[t][w-1]));
	return 0;
}
