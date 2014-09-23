#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#define INF 1000000000

using namespace std;

int dist[55][55];
int dp[55][1005];

class NegativeGraphDiv2 {
public:
	long long findMin(int, vector <int>, vector <int>, vector <int>, int);
};

long long NegativeGraphDiv2::findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
	int n=N;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dist[i][j]=INF;
		}
		dist[i][i]=0;
	}
	for(int i=0;i<s.size();i++)
	{
		dist[s[i]][t[i]]=min(weight[i],dist[s[i]][t[i]]);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	for(int i=1;i<=n;i++)
		dp[i][0]=dist[1][i];
	return dp[2][0];
	for(int j=1;j<=charges;j++)
		for(int i=1;i<=n;i++)
		{
			dp[i][j]=dp[i][j-1];
			for(int k=0;k<s.size();k++)
				dp[i][j]=min(dp[i][j],dist[t[k]][i]-weight[k]+dp[s[k]][j-1]);
		}
	return dp[n][charges];
}
