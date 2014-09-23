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
#define MAXN 100005

typedef long long ll;
using namespace std;

int a[MAXN],dp[MAXN],mark[MAXN];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(mark,0,sizeof(mark));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(mark[a[i]]==0)
				dp[i]=dp[i-1];
			else
				dp[i]=max(dp[i-1],dp[mark[a[i]]]+1);
			mark[a[i]]=i;
			ans=max(ans,dp[i]);
		}
/*		for(int i=1;i<=n;i++)
			cout<<dp[i]<<' ';
		cout<<endl;*/
		printf("%d\n",ans);
	}
	return 0;
}
