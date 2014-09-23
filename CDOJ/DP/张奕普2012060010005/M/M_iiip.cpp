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
#define INF -100005

typedef long long ll;
using namespace std;
int c[105],g[105],dp[105][105];

int main()
{
	int n,t;
	while(~scanf("%d%d",&n,&t))
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			int m,s;
			scanf("%d%d",&m,&s);
			for(int j=0;j<m;j++)
				scanf("%d%d",&c[j],&g[j]);
			//at least one
			if(s==0)
			{
				for(int j=0;j<=t;j++)
					dp[i+1][j]=INF;
				for(int j=0;j<m;j++)
					for(int k=t;k>=0;k--)
					{
						if(k>=c[j])
							dp[i+1][k]=max(max(dp[i+1][k],dp[i+1][k-c[j]]+g[j]),dp[i][k-c[j]]+g[j]);
						else
							dp[i+1][k]=max(dp[i+1][k],INF);
					}
			}
			else if(s==1)
			{
				for(int j=0;j<=t;j++)
					dp[i+1][j]=dp[i][j];
				for(int j=0;j<m;j++)
					for(int k=t;k>=0;k--)
					{
						if(k>=c[j])
							dp[i+1][k]=max(max(dp[i][k],dp[i+1][k]),dp[i][k-c[j]]+g[j]);
						else
							dp[i+1][k]=max(dp[i][k],dp[i+1][k]);
					}
			}
			else
			{
				for(int j=0;j<=t;j++)
					dp[i+1][j]=dp[i][j];
				for(int j=0;j<m;j++)
					for(int k=t;k>=0;k--)
					{
						if(k>=c[j])
							dp[i+1][k]=max(dp[i+1][k],dp[i+1][k-c[j]]+g[j]);
						else 
							dp[i+1][k]=max(dp[i+1][k],dp[i][k]);
					}
			}
//			cout<<i<<':'<<dp[i+1][t]<<endl;
		}
		int ans=dp[n][t];
		if(ans>=0)
			printf("%d\n",ans);
		else
			printf("-1\n");
	}
	return 0;
}
