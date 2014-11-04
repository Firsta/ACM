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
		ll a,b;
		scanf("%I64d%I64d",&a,&b);
		ll ans=0;
		for(ll i=a;i<=b;i++)
			ans+=(i*i*i);
		printf("Case #%d: %I64d\n",cas,ans);
	}
	return 0;
}
