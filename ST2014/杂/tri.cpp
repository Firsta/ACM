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

ll f[1000005];

int main(){
	int n;
	for(ll i=4;i<=1000000;i++)
		f[i]=f[i-1]+((i-1)*(i-2)/2-(i-1)/2)/2;
	while(~scanf("%d",&n)&&n>=3){
		printf("%lld\n",f[n]);
	}
	return 0;
}
