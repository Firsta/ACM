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

double jump[15],ex[505],dp[505];

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			ex[i]=0;
		for(int i=1;i<=k;i++)
			scanf("%lf",&jump[i]);
		for(int i=1;i<=n;i++){
			int q;
			scanf("%d",&q);
			while(q--){
				double c,x;
				scanf("%lf%lf",&c,&x);
				ex[i]+=c*x;
			}
		}
		for(int i=1;i<=n;i++)
			dp[i]=0.0;
		dp[1]=1.0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(i-j>=1){
					dp[i]=dp[i]+(double)(dp[i-j])*(double)(jump[j]);
				}
			}
		}
		double ans=0;
		for(int i=1;i<=n;i++)
			ans+=dp[i]*ex[i];
		printf("Case #%d: %.6f\n",cas,ceil(ans*1000000)/1000000);
	}
	return 0;
}
