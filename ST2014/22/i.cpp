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
#define INF 1000000009

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int x[100005];

ll extgcd(int a,int b,ll &x,ll &y){
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
ll mod_inverse(int a,int m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

//n!mod p(0<=n<p)
ll fact[100001];

ll mod_fact(int n,int p,int &e){
	e=0;
	if(n==0)
		return 1;
	ll res=mod_fact(n/p,p,e);
	e+=n/p;
	if(n/p%2!=0)
		return res*(p-fact[n%p])%p;
	return res*fact[n%p]%p;
}

ll mod_comb(int n,int k,int p){
	if(n<0||k<0||n<k)
		return 0;
	int e1,e2,e3;
	ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
//	cout<<a1<<' '<<a2<<' '<<a3<<' '<<endl;
	if(e1>e2+e3)
		return 0;
	return a1*mod_inverse(a2*a3%p,p)%p;
}

int main(){
	int n,m;
	fact[0]=1;
	for(int i=1;i<=100000;i++)
		fact[i]=fact[i-1]*i%INF;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%d",&x[i]);
		int l=0;int r=0;
		for(int i=0;i<n;i++){
			int tml,tmr;
			if(l>=x[i])
				tml=l-x[i];
			else if(r>=x[i])
				tml=((l%2)==(x[i]%2)?0:1);
			else
				tml=x[i]-r;
			if(r+x[i]<=m)
				tmr=r+x[i];
			else if(l+x[i]<=m)
				tmr=(((l+x[i])%2)==(m%2)?m:m-1);
			else
				tmr=2*m-(l+x[i]);
			l=tml;r=tmr;
		}
		ll ans=0;
//		cout<<l<<' '<<r<<endl;
		for(int i=l;i<=r;i++)
			if((i%2)==(l%2))
			ans+=mod_comb(m,i,INF);
		printf("%lld\n",ans);
	}
	return 0;
}
