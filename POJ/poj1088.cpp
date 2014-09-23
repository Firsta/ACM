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
#include<cmath>
#include<sstream>
#include<string>
#define MAXN 105
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int dp[MAXN][MAXN],grid[MAXN][MAXN],r,c;
int dfs(int x,int y){
	if(dp[x][y]!=0)
		return dp[x][y];
	dp[x][y]=1;
	if(x-1>=0&&grid[x-1][y]<grid[x][y])
		dp[x][y]=max(dp[x][y],dfs(x-1,y)+1);
	if(x+1<r&&grid[x+1][y]<grid[x][y])
		dp[x][y]=max(dp[x][y],dfs(x+1,y)+1);
	if(y-1>=0&&grid[x][y-1]<grid[x][y])
		dp[x][y]=max(dp[x][y],dfs(x,y-1)+1);
	if(y+1<c&&grid[x][y+1]<grid[x][y])
		dp[x][y]=max(dp[x][y],dfs(x,y+1)+1);
	return dp[x][y];
}
int main(){
	scanf("%d%d",&r,&c);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&grid[i][j]);
	int ans=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			ans=max(ans,dfs(i,j));
	printf("%d",ans);
	return 0;
}
