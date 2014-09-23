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
int dp[17][1<<8],card[17];

int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=0;i<=(1<<n)-1;i++)
	{
		int temp=((1<<n)-1)^i;
	//	cout<<temp<<endl;
		for(int j=temp;;j=(j-1)&temp)
		{
			cnt++;
			if(j==0)
				break;
		}
	//	cout<<time<<endl;
	}
//	cout<<cnt<<endl;
	int max=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&card[i]);
		if(card[i]>max)
			max=card[i];
	}
	int lim;
	for(int i=0;;i++)
		if((1<<i)>max)
		{
			lim=(1<<i);
			break;
		}
	dp[1][0^card[0]]+=2;
	dp[1][0]+=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<lim;j++)
		{
			dp[i+1][j]+=dp[i][j];
			dp[i+1][j^card[i]]+=dp[i][j]*2;
		}
	}
//	cout<<dp[1][0]<<' '<<dp[2][0]<<endl;
	int temp=dp[n][0];
//	cout<<temp<<endl;
	int ans=(temp+cnt)/2;
	printf("%d",ans);
	return 0;
}
