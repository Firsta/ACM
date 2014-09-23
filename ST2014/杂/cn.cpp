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
#define MAXN 70000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll quickpow(ll m,ll n,ll k){
	ll b=1;
	while(n>0){
		if(n&1)
			b=(b*m)%k;
		n=n>>1;
		m=(m*m)%k;
	}
	return b;
}

int isprime[MAXN];

int main(){
	ll n;
	memset(isprime,1,sizeof(isprime));
	isprime[1]=isprime[0]=0;
	for(int i=2;i<MAXN;i++){
		if(isprime[i]){
			for(int j=2*i;j<MAXN;j+=i)
				isprime[j]=0;
		}
	}
	while(~scanf("%lld",&n)&&n!=0){
		if(isprime[n]){
			printf("%lld is normal.\n",n);
		}
		else{
			bool flag=true;
			for(ll i=2;i<n;i++)
				if(quickpow(i,n,n)%n!=i){
					flag=false;
					break;
				}
			if(flag)
				printf("The number %lld is a Carmichael number.\n",n);
			else
				printf("%lld is normal.\n",n);
		}
	}
	return 0;
}
