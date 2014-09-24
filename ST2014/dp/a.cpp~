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

int a[355][355];
int dp[355];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<i+1;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++)
		dp[i]=a[n-1][i];
	for(int i=n-2;i>=0;i--)
		for(int j=0;j<i+1;j++)
			dp[j]=max(dp[j],dp[j+1])+a[i][j];
	printf("%d\n",dp[0]);
	return 0;
}
