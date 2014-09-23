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

ll jc[20];

int main(){
	jc[0]=1;
	for(int i=1;i<=17;i++)
		jc[i]=jc[i-1]*i;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p,n,k;
		scanf("%d%d%d",&p,&n,&k);
		ll ans=0;
		for(int i=1;i<=k;i++){
			ll c=(jc[k]/jc[i])/jc[k-i];
			if(i%2==1){
				ans+=c*jc[n-i];
			}
			else
				ans-=c*jc[n-i];
		}
		printf("%d ",p);
		printf("%lld\n",jc[n]-ans);
	}
	return 0;
}
