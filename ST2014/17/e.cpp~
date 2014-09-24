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
	for(int cas=1;cas<=t;cas++){
		ll n,x,y,z,t;
		scanf("%lld%lld%lld%lld%lld",&n,&x,&y,&z,&t);
		ll ans=0;
		for(ll i=0;i<=n;i++)
			for(ll j=i;j<=n;j++){
				ll nn=j-i;
				ll tmp=0;
				tmp+=nn*(nn-1)*y/2;
				tmp+=(n-j)*(nn*y+x);
				tmp*=(t+i*z);
				ans=max(ans,tmp);
			}
		for(ll i=0;i<=n;i++)
			for(ll j=i;j<=n;j++){
				ll nn=j-i;
				ll tmp=0;
				tmp+=i*(i-1)*y*t;
				tmp+=nn*(2*t+(nn-1)*z)*i*y/2;
				tmp+=(x+y*i)*(t+z*nn)*(n-j);
				ans=max(ans,tmp);
			}
		printf("Case #%d: ",cas);
		printf("%lld\n",ans);
	}
	return 0;
}
