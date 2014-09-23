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

int grid[8][8],dp[15][8][8][8][8],sum[8][8][8][8];

int getsum(int x1,int y1,int x2,int y2)
{
	int ret=0;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			ret+=grid[i][j];
	return ret*ret;
}

int dfs(int dep,int x1,int y1,int x2,int y2)
{
	if(dp[dep][x1][y1][x2][y2]!=-1)
		return dp[dep][x1][y1][x2][y2];
	else if(dep==1||x1==x2||y1==y2)
	{
		dp[dep][x1][y1][x2][y2]=sum[x1][y1][x2][y2];
		return sum[x1][y1][x2][y2];
	}
	else
	{
		dp[dep][x1][y1][x2][y2]=INT_MAX;
		for(int i=x1;i<x2;i++)
			dp[dep][x1][y1][x2][y2]=min(dp[dep][x1][y1][x2][y2],min(dfs(dep-1,x1,y1,i,y2)+sum[i+1][y1][x2][y2],dfs(dep-1,i+1,y1,x2,y2)+sum[x1][y1][i][y2]));
		for(int i=y1;i<y2;i++)
			dp[dep][x1][y1][x2][y2]=min(dp[dep][x1][y1][x2][y2],min(dfs(dep-1,x1,y1,x2,i)+sum[x1][i+1][x2][y2],dfs(dep-1,x1,i+1,x2,y2)+sum[x1][y1][x2][i]));
		return dp[dep][x1][y1][x2][y2];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	//get grid
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			scanf("%d",&grid[i][j]);
	//get sum
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			for(int r=0;r<8;r++)
				for(int s=0;s<8;s++)
					sum[i][j][r][s]=getsum(i,j,r,s);
	//init
	memset(dp,-1,sizeof(dp));
	int temp=dfs(n,0,0,7,7);
//	cout<<temp<<endl;
	double ans;
//	cout<<sum[0][0][7][7]<<endl;
	double t2=sum[0][0][7][7];
	t2=sqrt(t2);
	ans=sqrt((double)temp/n-(t2*t2)/(n*n));
	printf("%.3f",ans);
	return 0;
}
