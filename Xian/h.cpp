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

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int vis[MAXN],match[MAXN];

int main(){
	int n;
	while(~scanf("%d",&n)){
		fill(vis,vis+n+1,0);
		for(int i=n;i>=0;i--)if(!vis[i]){
			int now=0;
			int tmp=1;
			int tt=i;
			while(tt){
				if(tt%2==0)
					now+=tmp;
				tt/=2;
				tmp*=2;
			}
			match[i]=now;
			match[now]=i;
			vis[now]=vis[i]=1;
		}
		ll ans=0;
		for(int i=0;i<=n;i++)
			ans+=(i^match[i]);
		printf("%I64d\n",ans);
		for(int i=0;i<=n;i++){
			int tmp;
			scanf("%d",&tmp);
			if(i==0)
				printf("%d",match[tmp]);
			else
				printf(" %d",match[tmp]);
		}
		printf("\n");
	}
	return 0;
}
