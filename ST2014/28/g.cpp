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
#define MAXN 9000005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct node{
	int l,r,mid;
}qu[MAXN];

map<int,int> mapp1,mapp2;

int y11,y22,v;//[y11,y22]

int leftt[MAXN],nn[MAXN];//INF
int rightt[MAXN];

void updateleftt(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	if(y11<=L&&R<=y22){
		if(leftt[o]==-1)
			leftt[o]=v;
		else
			leftt[o]=min(leftt[o],v);
	}
	else{
		int M=L+(R-L)/2;
		if(y11<=M)
			updateleftt(lc,L,M);
		if(y22>M)
			updateleftt(rc,M+1,R);
	}
}

int _min;
void queryleftt(int o,int L,int R,int add){
	if(y11<=L&&y22>=R){
		if(leftt[o]!=-1)
			add=min(leftt[o],add);
		_min=min(_min,min(leftt[o],add));
	}
	else{
		int M=L+(R-L)/2;
		if(leftt[o]!=-1)
			add=min(add,leftt[o]);
		if(y11<=M)
			queryleftt(o*2,L,M,add);
		if(y22>M)
			queryleftt(o*2+1,M+1,R,add);
	}
}

void updaterightt(int o,int L,int R){
	int lc=o*2,rc=o*2+1;
	if(y11<=L&&R<=y22){
		if(rightt[o]==-1)
			rightt[o]=v;
		else
			rightt[o]=max(rightt[o],v);
	}
	else{
		int M=L+(R-L)/2;
		if(y11<=M)
			updaterightt(lc,L,M);
		if(y22>M)
			updaterightt(rc,M+1,R);
	}
}

int _max;
void queryrightt(int o,int L,int R,int add){
	if(rightt[o]!=-1)
		add=max(rightt[o],add);
	if(y11<=L&&y22>=R){
		_max=max(_max,add);
	}
	else{
		int M=L+(R-L)/2;
		if(y11<=M)
			queryrightt(o*2,L,M,add);
		if(y22>M)
			queryrightt(o*2+1,M+1,R,add);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n,m;
		memset(leftt,-1,sizeof(leftt));
		memset(rightt,-1,sizeof(rightt));
		scanf("%d%d",&n,&m);
		vector<int> xs;
		int cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&qu[i].l,&qu[i].r);
			qu[i].mid=(qu[i].l+qu[i].r)/2;
			xs.push_back(qu[i].l);
			xs.push_back(qu[i].r);
			xs.push_back(qu[i].mid);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&nn[i]);
			xs.push_back(nn[i]);
		}
		sort(xs.begin(),xs.end());
		xs.erase(unique(xs.begin(),xs.end()),xs.end());
		mapp1.clear();
		int N=xs.size();
		for(int i=0;i<N;i++)
			mapp1[xs[i]]=i+1;
		for(int i=0;i<m;i++){
			y11=y22=mapp1[nn[i]];
			v=nn[i];
			updateleftt(1,1,N);
			updaterightt(1,1,N);
		}
		for(int i=0;i<n;i++){
			v=qu[i].l;
			y11=mapp1[qu[i].l];
			y22=mapp1[qu[i].mid];
			updateleftt(1,1,N);
			v=qu[i].r;
			y11=mapp1[qu[i].mid]+1;
			y22=mapp1[qu[i].r];
			updaterightt(1,1,N);
		}
		printf("Case %d:\n",cas);
		for(int i=0;i<m;i++){
			_min=nn[i];
			_max=nn[i];
			y22=y11=mapp1[nn[i]];
			queryleftt(1,1,N,nn[i]);
			queryrightt(1,1,N,nn[i]);
			printf("%d\n",max(nn[i]-_min,_max-nn[i]));
		}
	}
	return 0;
}

