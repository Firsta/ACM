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

int a[20005];

int main(){
	int n,k;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		if(k>=n){
			printf("%d\n",a[n-1]-a[0]);
			continue;
		}
		int minn=1000000000;
		for(int i=0;i+k-1<n;i++)
			minn=min(minn,a[i+k-1]-a[i]);
		printf("%d\n",minn);
	}
	return 0;
}
