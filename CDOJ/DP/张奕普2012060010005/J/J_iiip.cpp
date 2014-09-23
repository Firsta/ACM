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
#define MAXN 12

typedef long long ll;
using namespace std;

ll dp[2][1<<MAXN];

int main()
{
	int h,w;
	while(~scanf("%d%d",&h,&w))
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=h-1;i>=0;i--)
			for(int j=w-1;j>=0;j--)
			{
				for(ll hash=0;hash<(1<<w);hash++)
				{
					if(hash&(1<<j))
						dp[1][hash]=dp[0][hash&~(1<<j)];
					else
					{
						ll res=0;
						if(j+1<w&&!(hash&(1<<(j+1))))
							res+=dp[0][hash|1<<(j+1)];
						if(i+1<h)
							res+=dp[0][hash|1<<j];
						dp[1][hash]=res;
					}
				}
				int temp[1<<MAXN];
				for(ll i=0;i<(1<<w);i++)
					temp[i]=dp[0][i];
				for(ll i=0;i<(1<<w);i++)
					dp[0][i]=dp[1][i];
				for(ll i=0;i<(1<<w);i++)
					dp[1][i]=temp[i];
			}
		cout<<dp[0][0]<<endl;
	}
	return 0;
}
