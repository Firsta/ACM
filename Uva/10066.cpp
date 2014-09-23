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

typedef long long ll;
using namespace std;

int t1[105],t2[105];
int dp[105][105];

int main()
{
	int m,n;
	int cas=1;
	while(cin>>m>>n&&(m!=0&&n!=0))
	{
		for(int i=0;i<m;i++)
			cin>>t1[i];
		for(int j=0;j<n;j++)
			cin>>t2[j];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				if(t1[i]==t2[j])
					dp[i+1][j+1]=dp[i][j]+1;
				else
				{
					dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
				}
			}
		cout<<"Twin Towers #"<<cas++<<endl<<"Number of Tiles : "<<dp[m][n]<<endl<<endl;
	}
	return 0;
}
