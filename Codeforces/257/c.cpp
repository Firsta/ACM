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
using namespace std;

int main(){
	ll n,m,k,ans;
	cin>>n>>m>>k;
	if(n+m-2<k){
		cout<<-1<<endl;
		return 0;
	}
	else if(k<=n-1&&k<=m-1){
		ans=max(n/(k+1)*m,m/(k+1)*n);
	}else if(k<=n-1){
		ans=max(n/(k+1)*m,1*n/(k-m+2));
	}else if(k<=m-1){
		ans=max(m/(k+1)*n,1*m/(k-n+2));
	}else{
		ans=max(1*n/(k-m+2),1*m/(k-n+2));
	}
	cout<<ans<<endl;
	return 0;
}
