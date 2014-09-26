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
#define lc (o*2)
#define rc (o*2+1)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n,m;

ll maxv[4*MAXN],sumv[4*MAXN];

ll query(int o,int L,int R,int l,int r){
	if(l<=L&&r>=R)
		return sumv[o];
	else{
		int M=L+(R-L)/2;
		ll sum=0;
		if(l<=M)
			sum+=query(lc,L,M,l,r);
		if(r>M)
			sum+=query(rc,M+1,R,l,r);
		return sum;
	}
}

void build(int o,int L,int R){
	if(L==R){
		scanf("%I64d",&sumv[o]);
		maxv[o]=sumv[o];
	}else{
		int M=L+(R-L)/2;
		build(lc,L,M);
		build(rc,M+1,R);
		maxv[o]=max(maxv[lc],maxv[rc]);
		sumv[o]=sumv[lc]+sumv[rc];
	}
}

void ssqrt(int o,int L,int R,int l,int r){
	if(maxv[o]==1||maxv[o]==0)
		return;
	else if(L==R){
		ll tmp=(ll)sqrt(sumv[o]);
		sumv[o]=tmp;
		maxv[o]=tmp;
	}else{
		int M=L+(R-L)/2;
		if(l<=M)
			ssqrt(lc,L,M,l,r);
		if(r>M)
			ssqrt(rc,M+1,R,l,r);
		maxv[o]=max(maxv[lc],maxv[rc]);
		sumv[o]=sumv[lc]+sumv[rc];
	}
}

int main(){
	int cas=0;
	while(scanf("%d",&n)!=EOF){
		cas++;
		memset(maxv,0LL,sizeof(maxv));
		memset(sumv,0LL,sizeof(sumv));
		build(1,1,n);
		scanf("%d",&m);
		printf("Case #%d:\n",cas);
		while(m--){
			int t;
			scanf("%d",&t);
			if(t==0){
				int x,y;
				scanf("%d%d",&x,&y);
				ssqrt(1,1,n,min(x,y),max(x,y));
			}else if(t==1){
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%I64d\n",query(1,1,n,min(x,y),max(x,y)));
			}
		}
		printf("\n");
	}
	return 0;
}
