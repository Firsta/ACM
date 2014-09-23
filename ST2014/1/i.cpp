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

struct vec{
	__int64 x,y;
}a[35];

__int64 S(int i,int j,int k){
	return abs(a[i].x*a[j].y+a[i].y*a[k].x+a[j].x*a[k].y-a[j].y*a[k].x-a[i].y*a[j].x-a[i].x*a[k].y);
}

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n;
		__int64 cnt=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%I64d%I64d",&a[i].x,&a[i].y);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for(int k=j+1;k<n;k++)
					for(int l=k+1;l<n;l++){
						if(S(l,i,j)+S(l,i,k)+S(l,j,k)==S(i,j,k)
								||S(i,l,j)+S(i,l,k)+S(i,j,k)==S(l,j,k)
								||S(j,l,i)+S(j,i,k)+S(j,l,k)==S(l,i,k)
								||S(k,i,j)+S(k,l,i)+S(k,l,j)==S(i,j,l))
							cnt++;
					}
		__int64 ans=n*(n-1)*(n-2)*(n-3)/(4*3*2);
		printf("Case %d: ",cas);
		printf("%I64d\n",ans-cnt);
	}
	return 0;
}
