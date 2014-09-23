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
#include<sstream>
#include<string>
#define MAXN 400005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll sumv[MAXN],addv[MAXN];

int l,r;
ll v;

void maintain(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	sumv[o]=0;
	if(R>L)
		sumv[o]=sumv[lc]+sumv[rc];
	sumv[o]+=addv[o]*(R-L+1);
}

void update(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	if(l<=L&&r>=R)
		addv[o]+=v;
	else{
		int M=L+(R-L)/2;
		if(l<=M)
			update(lc,L,M);
		if(r>M)
			update(rc,M+1,R);
	}
	maintain(o,L,R);
}

ll _sum;
void query(int o,int L,int R,ll add){
	if(l<=L&&r>=R){
		_sum+=sumv[o]+add*(R-L+1);
	}else{
		int M=L+(R-L)/2;
		if(l<=M)
			query(o*2,L,M,add+addv[o]);
		if(r>M)
			query(o*2+1,M+1,R,add+addv[o]);
	}
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(addv,0,sizeof(addv));
		memset(sumv,0,sizeof(sumv));
		for(int i=1;i<=n;i++){
			scanf("%lld",&v);
			l=i,r=i;
			update(1,1,n);
		}
		while(m--){
			int s;
			scanf("%d",&s);
			if(s==0){
				_sum=0;
				scanf("%d%d",&l,&r);
				query(1,1,n,0);
				printf("%lld\n",_sum);
			}else{
				scanf("%d%d%lld",&l,&r,&v);
				update(1,1,n);
			}
		}
	}
	return 0;
}
