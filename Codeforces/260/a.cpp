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

int cnt[100005];
ll dp[100005];

int main(){
	int n,tmp;
	cin>>n;
	memset(cnt,0,sizeof(cnt));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>tmp;
		cnt[tmp]++;
	}
	ll ans=0;
	dp[1]=cnt[1];
	ll maxx=0;
	for(int i=2;i<100005;i++){
		maxx=max(dp[i-2],maxx);
		dp[i]=maxx+(ll)cnt[i]*(ll)i;
	}
//	for(int i=1;i<=9;i++)
//		cout<<dp[i]<<' ';
//	cout<<endl;
	for(int i=1;i<100005;i++)
		ans=max(ans,dp[i]);
	memset(dp,0,sizeof(dp));
	maxx=0;
	for(int i=100000;i>=1;i--){
		maxx=max(maxx,dp[i+2]);
		dp[i]=maxx+(ll)cnt[i]*(ll)i;
	}
	for(int i=1;i<100005;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
