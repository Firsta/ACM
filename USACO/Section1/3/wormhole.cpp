/*
ID: firstaw1
PROG: wormhole
LANG: C++
*/
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

int n,ans,x[13],y[13];

int main(){
	freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			if(y[i]==y[j]){
				int a=x[i],b=x[j];
				bool flag=true;
				if(a>b)
					swap(a,b);
				for(int k=0;k<n;k++)
					if(y[k]==y[i]&&x[k]>a&&x[k]<b)
						flag=false;
				if(flag)
					ans++;
			}
		}
	printf("%d\n",ans);
	return 0;
}
