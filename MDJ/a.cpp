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

int h[55];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&h[i]);
		int ans=0;
		for(int i=2;i<=n-1;i++)
			if(h[i]>h[i-1]&&h[i]>h[i+1])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
