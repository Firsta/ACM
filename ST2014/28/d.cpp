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
#define INF 10000000000007

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll fact[10005];
ll a[10005][10005];

ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;y=0;
	}
	return d;
}

//ax=1(mod m)=>ax-mk=1
ll mod_inverse(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

ll A(int m,int n){
	if(a[m][n]!=0)
		return a[m][n];
	else{
		a[m][n]=fact[m]%INF*mod_inverse(fact[n]%INF,INF)%INF;
		return a[m][n];
	}
}

int main(){
	fact[0]=1;
	for(int i=1;i<=10000;i++)
		fact[i]=(fact[i-1]%INF)*(i%INF)%INF;
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int l,m,n;
		ll ans=0;
		scanf("%d%d%d",&l,&m,&n);
		int L=l*l;
		for(int i=m;i<=n;i++){
			ans=(ans%INF+A(L,L-i)%INF)%INF;
		}
		printf("Case %d: ",cas);
		printf("%lld",ans);
		if(cas>=1&&cas<t)
			printf("\n");
	}
	return 0;
}
