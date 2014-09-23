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
#define MAXN 10005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int a[MAXN];
int dp[MAXN][105];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	dp[0][(a[0]%k+k)%k]=1;
	dp[0][(a[0]%k+k)%k]=1;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<k;j++)
			if(dp[i][j]){
				dp[i+1][((j+a[i+1])%k+k)%k]=1;
				dp[i+1][((j-a[i+1])%k+k)%k]=1;
			}
	if(dp[n-1][0])
		printf("Divisible");
	else
		printf("Not divisible");
	return 0;
}
