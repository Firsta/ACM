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

int main(){
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		double n,m;
		int a,b;
		scanf("%lf%lf%d%d",&n,&m,&a,&b);
		printf("Case #%d: ",cas);
		if((b*10<(a+b)*m-a*n)||(a*n>(a+b)*m))
			printf("Impossible\n");
		else{
			double ans=(a*m+b*m-a*n)/b;
			double out=(ceil(ans*100))/100;
			printf("%.2f\n",out);
		}
	}
	return 0;
}
