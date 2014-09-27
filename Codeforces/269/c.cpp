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
	ll n;
	scanf("%I64d",&n);
	ll ans=0;
	if((n+1)%3==0){
		for(ll i=1;;i+=3){
			if(n>=i*(i+1)/2*3-i)
				ans++;
			else
				break;
		}
	}
	if((n+1)%3==2){
		for(ll i=2;;i+=3){
			if(n>=i*(i+1)/2*3-i)
				ans++;
			else
				break;
		}
	}
	if((n+1)%3==1){
		for(ll i=3;;i+=3){
			if(n>=i*(i+1)/2*3-i)
				ans++;
			else
				break;
		}
	}
	printf("%I64d",ans);
	return 0;
}
