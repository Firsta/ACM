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
#define MAXN 12

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int prize[MAXN],cnt[35];

set<int> se[12];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			int k;
			se[i].clear();
			scanf("%d",&k);
			int tmp;
			while(k--){
				scanf("%d",&tmp);
				se[i].insert(tmp);
			}
			scanf("%d",&tmp);
			prize[i]=tmp;
		}
		int cash=0;
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=m;j++){
			int tmp;
			scanf("%d",&tmp);
			cnt[j]=tmp;
		}
		for(int i=0;i<n;i++){
			int minn=105;
			for(int j=1;j<=m;j++)
				if(se[i].count(j))
					minn=min(minn,cnt[j]);
			cash+=minn*prize[i];
		}
		printf("%d\n",cash);
	}
	return 0;
}
