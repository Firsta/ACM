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
#define MAXV 1005
#define MAXP 1005

typedef long long ll;
using namespace std;

int dp[MAXV][MAXP];//dp[i][j],1~i villages j post
int w[MAXV][MAXV];//i~j 1 post
int s[MAXV][MAXP];
int pos[MAXV];
int v,p;

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	scanf("%d%d",&v,&p);
	for(int i=1;i<=v;i++)
		scanf("%d",&pos[i]);
	for(int i=1;i<=v;i++)
		w[i][i]=0;
	for(int i=1;i<=v;i++)
		for(int j=i+1;j<=v;j++)
			w[i][j]=w[i][j-1]+pos[j]-pos[(i+j)/2];
	for(int i=1;i<=v;i++)
		s[i][1]=0;
	for(int i=1;i<=v;i++)
		dp[i][1]=w[1][i];
	for(int j=2;j<=p;j++)
	{
		s[v+1][j]=v;
		for(int i=v;i>j;i--)
		{
			dp[i][j]=INT_MAX;
			int tmp;
			for(int k=s[i][j-1];k<=s[i+1][j];k++)
				if(dp[k][j-1]+w[k+1][i]<dp[i][j])
				{
					dp[i][j]=dp[k][j-1]+w[k+1][i];
					tmp=k;
				}
			s[i][j]=tmp;
		}
	}
	printf("%d\n",dp[v][p]);
	return 0;
}
