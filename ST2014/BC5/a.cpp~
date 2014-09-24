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

bool judge(ll x){
	int cnt=0;
	int cnto=0;
	int cnte=0;
	while(x){
		int tmp=x%10;
		if(cnt%2==0)
			cnte+=tmp;
		else
			cnto+=tmp;
		cnt++;
		x/=10;
	}
	if(cnto==cnte-3)
		return true;
	return false;
}

int main(){
	ll l,r;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&l,&r);
		ll i;
		for(i=l;i<=r;i++){
			if(i%11==3&&!judge(i))
				break;
		}
		if(i>r)
			printf("-1\n");
		else
			printf("%lld\n",i);
	}
	return 0;
}
