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

int a[55];

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int cnth=0,cntl=0;
		for(int i=1;i<n;i++){
			if(a[i]<a[i-1])
				cntl++;
			else if(a[i]>a[i-1])
				cnth++;
		}
		printf("Case %d: %d %d\n",cas,cnth,cntl);
	}
	return 0;
}
