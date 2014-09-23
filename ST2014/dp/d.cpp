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

struct node{
	ll s,t,w;
}a[1100];

bool cmp(const node &a,const node &b){
	return a.s<b.s;
}

ll dp[1000100];

int main(){
	int n,m,r,tmp;
	scanf("%d%d%d",&n,&m,&r);
	for(int i=0;i<m;i++)
		scanf("%lld%lld%lld",&a[i].s,&a[i].t,&a[i].w);
	sort(a,a+m,cmp);
	ll maxx=0,j=0;
	for(int i=0;i<=n;i++){
		if(i-r>=0)
			maxx=max(maxx,dp[i-r]);
		if(j<m&&i==a[j].s){
			tmp=a[j].s;
			for(;j<m&&a[j].s==tmp;j++)
				dp[a[j].t]=max(dp[a[j].t],maxx+a[j].w);
		}
	}
	ll ans=0;
//	for(int i=0;i<=n;i++)
//		printf("%d ",dp[i]);
//	cout<<endl;
	for(int i=0;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}
