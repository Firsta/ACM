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

char city[105];
int dp[105][105];

int main()
{
	string s1,s2;
	int cas=1;
	while(getline(cin,s1)&&s1!="#")
	{
		getline(cin,s2);
		memset(dp,0,sizeof(dp));
		int m=s1.size(),n=s2.size();
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				if(s1[i]==s2[j])
					dp[i+1][j+1]=dp[i][j]+1;
				else
					dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		cout<<"Case #"<<cas++<<": you can visit at most "<<dp[m][n]<<" cities."<<endl;
	}
	return 0;
}
