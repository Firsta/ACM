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
#define eps 0.000001

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	double aa=(double)a;
	double bb=(double)b;
	double cc=(double)c;
	if(a==0){
		if(b==0){
			if(c==0){
				printf("-1");
			}else{
				printf("0");
			}
		}else{
			double ans=-cc/bb;
			printf("1\n%.12f",ans);
		}
	}else{
		if(b*b-4*a*c<0){
			printf("0");
		}else if(b*b-4*a*c==0){
			double ans=-bb/(2*aa);
			printf("1\n%.12f",ans);
		}else{
			double ans1=(-bb+sqrt(bb*bb-4*aa*cc))/(2*aa);
			double ans2=(-bb-sqrt(bb*bb-4*aa*cc))/(2*aa);
			printf("2\n%.12f\n%.12f",min(ans1,ans2),max(ans1,ans2));
		}
	}
	return 0;
}
