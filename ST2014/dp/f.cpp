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

int dp[100005];
int a[105],c[105];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&c[i]);
		for(int i=1;i<=m;i++)
			dp[i]=-1;
		dp[0]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<=m;j++){
				if(dp[j]>=0)
					dp[j]=c[i];
				else if(j>=a[i]&&dp[j-a[i]]>0)
					dp[j]=max(dp[j],dp[j-a[i]]-1);
				else
					dp[j]=-1;
			}
		int ans=0;
		for(int i=1;i<=m;i++)
			if(dp[i]!=-1)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
