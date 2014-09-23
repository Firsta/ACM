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
#define INF 430000

typedef long long ll;
using namespace std;

int dp[20][210005];
int value[25],size[25],cnt;
int a[6];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	for(int cas=1;;cas++)
	{
		int sum=0;
		cnt=0;
		for(int i=0;i<6;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0)
				continue;
			sum+=a[i]*(i+1);
			int c=a[i];
			for(int k=1;k<=c;k<<=1)
			{
				value[cnt]=k*(i+1);
				size[cnt++]=i+1;
				c-=k;
			}
			if(c>0)
			{
				value[cnt]=c*(i+1);
				size[cnt++]=i+1;
			}
		}
		bool flag=false;
		for(int i=0;i<6;i++)
			if(a[i]!=0)
				flag=true;
		if(!flag)
			break;
		printf("Collection #%d:\n",cas);
		if(sum%2!=0)
		{
			printf("Can't be divided.\n");
			continue;
		}
		sum/=2;
		for(int i=0;i<=cnt;i++)
			for(int j=0;j<=sum;j++)
				dp[i][j]=-INF;
		dp[0][0]=0;
		for(int i=0;i<cnt;i++)
			for(int j=0;j<=sum;j++)
			{
				if(j-value[i]<0)
					dp[i+1][j]=dp[i][j];
				else
					dp[i+1][j]=max(dp[i][j],dp[i][j-value[i]]+size[i]);
			}
		if(dp[cnt][sum]!=-INF)
			printf("Can be divided.\n");
		else
			printf("Can't be divided.\n");
	}
	return 0;
}
