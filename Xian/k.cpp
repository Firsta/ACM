#include<cstdio>
#include<algorithm>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
	double a,b,c,d,e,f;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)){
		double ans=min(1.0/a,min(1.0/b,1.0/c));
		printf("%.7f\n",ans);
	}
	return 0;
}
