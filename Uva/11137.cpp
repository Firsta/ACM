/************************************************
 * Author:		iiip
 * File name:		11137.cpp
 * Created time:	2014/4/4 22:49:47
 * Email:		firstawhois@gmail.com
 * *********************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cmath>
using namespace std;

long long dp[25000];
int coin[25];
int main()
{
	for(int i=1;i<=22;i++)
		coin[i]=i*i*i;
	int n;
	while(cin>>n)
	{
		int i;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=22;i++)
			if(coin[i]>n)
				break;
		dp[0]=1;
		i--;
		for(int j=1;j<=i;j++)
			for(int k=0;k<=n;k++)
				dp[k+coin[j]]+=dp[k];
		cout<<dp[n]<<endl;
	}
	return 0;
}
