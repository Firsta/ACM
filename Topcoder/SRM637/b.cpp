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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int dp[2][100];

class PathGameDiv2{
	public:
		int calc(vector <string> board){
			int n=board[0].size();
			for(int i=0;i<2;i++)
				for(int j=0;j<n;j++)
					dp[i][j]=1000;
			if(board[0][0]=='.')
				dp[0][0]=1;
			if(board[1][0]=='.')
				dp[1][0]=1;
			for(int i=1;i<n;i++){
				if(board[0][i]=='.'){
					if(board[0][i-1]=='.')
						dp[0][i]=min(dp[0][i],dp[0][i-1]+1);
					if(board[1][i]=='.'&&board[1][i-1]=='.')
						dp[0][i]=min(dp[0][i],dp[1][i-1]+2);
				}
				if(board[1][i]=='.'){
					if(board[1][i-1]=='.')
						dp[1][i]=min(dp[1][i],dp[1][i-1]+1);
					if(board[0][i]=='.'&&board[0][i-1]=='.')
						dp[1][i]=min(dp[1][i],dp[0][i-1]+2);
				}
			}
			int cnt=0;
			for(int i=0;i<2;i++)
				for(int j=0;j<n;j++)
					if(board[i][j]=='#')
						cnt++;
			int ans=min(dp[1][n-1],dp[0][n-1]);
			return 2*n-ans-cnt;
		}
};
