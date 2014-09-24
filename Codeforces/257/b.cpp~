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
#define INF 1e9+7

typedef long long ll;
using namespace std;

ll f[10];

int main(){
	ll x,y,n;
	cin>>x>>y>>n;
	f[1]=x;f[2]=y;
	for(int i=3;i<=6;i++)
		f[i]=f[i-1]-f[i-2];
	f[0]=f[6];
	int ans=f[n%6];
	ans=ans%1000000007;
	if(ans<0)
		ans+=1000000007;
	cout<<ans<<endl;
	return 0;
}
