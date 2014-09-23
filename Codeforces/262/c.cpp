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
#define MAXN 700005
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll sumv[MAXN],addv[MAXN];
ll sumd[MAXN],addd[MAXN];

int y11,y22;//[y11,y22]
ll v;
void maintain1(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	sumv[o]=0;
	if(R>L){
		sumv[o]=sumv[lc]+sumv[rc];
	}
	sumv[o]+=addv[o]*(R-L+1);
}

void update1(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	if(y11<=L&&R<=y22)
		addv[o]+=v;
	else{
		int M=L+(R-L)/2;
		if(y11<=M)
			update1(lc,L,M);
		if(y22>M)
			update1(rc,M+1,R);
	}
	maintain1(o,L,R);
}

int _sum;

void maintain2(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	sumd[o]=0;
	if(R>L){
		sumd[o]=sumv[lc]+sumv[rc];
	}
	sumd[o]+=addd[o]*(R-L+1);
}

void update2(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	if(y11<=L&&R<=y22)
		addd[o]+=v;
	else{
		int M=L+(R-L)/2;
		if(y11<=M)
			update2(lc,L,M);
		if(y22>M)
			update2(rc,M+1,R);
	}
	maintain2(o,L,R);
}

void query2(int o,int L,int R,ll add){
	if(y11<=L&&y22>=R){
		_sum+=sumd[o]+add*(R-L+1);
	}else{
		int M=L+(R-L)/2;
		if(y11<=M)
			query2(o*2,L,M,add+addd[o]);
		if(y22>M)
			query2(o*2+1,M+1,R,add+addd[o]);
	}
}

int main(){
	int n,m,w;
	cin>>n>>m>>w;
	ll tmp;
	ll minn=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		y11=y22=i;
		v=tmp;
		update1(1,1,n);
		minn=min(tmp,minn);
	}
	int l=minn-1,r=minn+m+1;
	while(r-l>1){
		for(int i=0;i<MAXN;i++){
			addd[i]=addv[i];
			sumd[i]=sumv[i];
		}
		int mid=(l+r)/2;
		ll cnt=0;
		for(int i=1;i<=n;i++){
			y11=y22=i;
			_sum=0;
			query2(1,1,n,0);
			if(_sum<mid){
				cnt+=mid-_sum;
				y11=i;
				y22=min(i+w-1,n);
				v=mid-_sum;
				update2(1,1,n);
			}
		}
		if(cnt>m)
			r=mid;
		else
			l=mid;
	}
	cout<<l<<endl;
	return 0;
}
