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

ll S(ll x){
	ll res=0;
	while(x){
		res+=x%10;
		x/=10;
	}
	return res;
}

ll quick_pow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1)
			res=res*x;
		x=x*x;
		n>>=1;
	}
	return res;
}

int main(){
	ll a,b,c;
	cin>>a>>b>>c;
	vector<ll> ans;
	for(ll i=1;i<=81;i++){
		ll x=b*quick_pow(i,a)+c;
		if(x<1000000000&&x>0&&S(x)==i)
			ans.push_back(x);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size();
	if(ans.size()!=0){
		cout<<endl;
		cout<<ans[0];
		for(int i=1;i<ans.size();i++)
			cout<<' '<<ans[i];
	}
	return 0;
}
