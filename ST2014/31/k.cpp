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
#define MAXN 100005

typedef __int64 ll;
typedef unsigned long long ull;
using namespace std;

ll sumv[MAXN];

int main(){
	int n;
	while(~scanf("%d",&n)&&(n)){
		int m;
		scanf("%d",&m);
		memset(sumv,0,sizeof(sumv));
		while(m--){
			int l,r;ll d;
			scanf("%d%d%I64d",&l,&r,&d);
			sumv[l]+=d;
			sumv[r+1]-=d;
		}
		for(int i=1;i<=n;i++)
			sumv[i]=sumv[i]+sumv[i-1];
		for(int i=1;i<=n;i++)
			sumv[i]=sumv[i]+sumv[i-1];
		int k;int ans=0;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			ll h;
			int x;
			scanf("%I64d%d",&h,&x);
			if(sumv[n]-sumv[x-1]<h){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
