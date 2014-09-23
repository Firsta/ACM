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
typedef unsigned long long ull;
using namespace std;

int n,a,b,c;

int aa[25],bb[55];

int f(int ta,int tb){
	int d=abs(ta-tb);
	return a*d*d+b*d+c;
}

int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&a,&b,&c);
		for(int i=0;i<n;i++)
			scanf("%d",&aa[i]);
		sort(aa,aa+n);
		int l=0,r=n-1;
		for(int i=0;i<n;i+=2){
			if(i+1>=n){
				bb[l]=aa[i];
				break;
			}
			else{
				int minn=min(aa[i],aa[i+1]);
				int maxx=aa[i]+aa[i+1]-minn;
				bb[l++]=minn;
				bb[r--]=maxx;
			}
		}
		int up=0;
	//	for(int i=0;i<n;i++)
	//		cout<<bb[i]<<' ';
	//	cout<<endl;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				up+=bb[i]*bb[j]*f(i,j);
	//	cout<<up<<endl;
		up*=2;
		for(int i=0;i<n;i++)
			up+=bb[i]*bb[i]*c;
	//	cout<<up<<endl;
		int gg=gcd(up,10000);
		printf("%d/%d\n",up/gg,10000/gg);
	}
	return 0;
}
