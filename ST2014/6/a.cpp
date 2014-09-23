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
#define INF 1000000

int dp[505][505];
int grid[505][505];

typedef long long ll;
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int r,c;
		scanf("%d%d",&r,&c);
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				scanf("%d",&grid[i][j]);
		dp[0][0].s=0;dp[0][0].c=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++){
				if(i==1){
					if(grid[i][j]>=0){
						dp[i][j].s=dp[i][j-1].s;
						dp[i][j].c+=grid[i][j];
					}else if(grid[i][j]<){
						if(dp[i][j].c>=-grid[i][j]){
							dp[i][j].s=dp[i][j-1].s;
							dp[i][j].c-=grid[i][j];
						}
					}
				}
			}
	}
	return 0;
}
