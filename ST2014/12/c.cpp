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

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		ll sum=0,maxx=0;
		for(int i=0;i<n;i++){
			ll tmp;
			scanf("%lld",&tmp);
			sum+=tmp;
			maxx=max(maxx,tmp);
		}
		ll ans=sum/m;
		if(sum%m!=0)
			ans+=1;
		ans=max(ans,maxx);
		printf("%lld\n",ans);
	}
	return 0;
}
