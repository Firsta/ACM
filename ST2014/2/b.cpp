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

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		double d,a,b,f;
		scanf("%lf%lf%lf%lf",&d,&a,&b,&f);
		double ans;
		ans=(d/(a+b))*f;
		printf("%d ",n);
		int tmp=floor(ans*1000);
		ans=(double(tmp)/1000);
		printf("%.2f\n",ans);
	}
	return 0;
}
