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
#define MAXN 200005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct Point{
	ll x,y;
}p[MAXN],p1[MAXN],p2[MAXN],r1,r2;

ll ra(Point a){
	return (a.x-r1.x)*(a.x-r1.x)+(a.y-r1.y)*(a.y-r1.y);
}

ll rb(Point a){
	return (a.x-r2.x)*(a.x-r2.x)+(a.y-r2.y)*(a.y-r2.y);;
}

bool cmp1(const Point &a,const Point &b){
	return ra(a)<ra(b);
}

bool cmp2(const Point &a,const Point &b){
	return rb(a)<rb(b);
}

int main(){
	int n;
	int cas=0;
	while(~scanf("%d",&n)){
		cas++;
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			scanf("%lld%lld",&p[i].x,&p[i].y);
			p1[i]=p2[i]=p[i];
		}
		scanf("%lld%lld%lld%lld",&r1.x,&r1.y,&r2.x,&r2.y);
		sort(p1,p1+n,cmp1);
		sort(p2,p2+n,cmp2);
		int q;
		scanf("%d",&q);
		ll R1,R2;
		printf("Case %d:\n",cas);
		while(q--){
			scanf("%lld%lld",&R1,&R2);
			int t1,t2;
			int lb=-1,ub=n;
			while(ub-lb>1){
				int mid=(lb+ub)/2;
				if(ra(p1[mid])>R1*R1)
					ub=mid;
				else
					lb=mid;
			}
			t1=ub;
			lb=-1;ub=n;
			while(ub-lb>1){
				int mid=(lb+ub)/2;
				if(rb(p2[mid])>R2*R2)
					ub=mid;
				else
					lb=mid;
			}
			t2=ub;
	//		cout<<t1<<' '<<t2<<endl;
			if(t1+t2<n)
				printf("%d\n",n-t1-t2);
			else
				printf("0\n");
		}
	}
	return 0;
}
