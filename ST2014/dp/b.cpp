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
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll dp[1000005];

int main(){
	int n;
	scanf("%d",&n);
	dp[1]=1;
	for(int i=2;i<=n;i++){
		if(i%2)
			dp[i]=dp[i-1];
		else
			dp[i]=(dp[i/2]+dp[i-1])%INF;
	}
	printf("%d\n",dp[n]);
	return 0;
}
