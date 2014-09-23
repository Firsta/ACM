#include<iostream>
#include<cstdio>
#include<cmath>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(){
	double h1,h2,d1,d2,a,b;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&h1,&h2,&d1,&d2,&a,&b)){
		double delta;
		delta=4*b*b*d2*d2-4*(a+b)*(b*d2*d2-h1);
		if(delta<0){
			printf("No\n");
			continue;
		}
		double x1,x2,x=-1;
		delta=sqrt(delta);
		x1=(2*b*d2+delta)/(2*(a+b));
		x2=(2*b*d2-delta)/(2*(a+b));
		if(x1<=d2&&x1>=0){
			x=x1;
			if(x>=d1){
				if(a*d1*d1<=h1-h2){
					printf("Yes\n");
					continue;
				}
			}
			else{
				double y1;
				y1=b*(d2-x)*(d2-x);
				if(y1-h2>=b*(d1-x1)*(d1-x1)){
					printf("Yes\n");
					continue;
				}
			}
		}
		else if(x2<=d2&&x2>=0){
			x=x2;
			if(x>=d1){
				if(a*d1*d1<=h1-h2){
					printf("Yes\n");
					continue;
				}
			}else{
				double y1;
				y1=b*(d2-x)*(d2-x);
				if(y1-h2>=b*(d1-x1)*(d1-x1)){
					printf("Yes\n");
					continue;
				}
			}
		}
		printf("No\n");
	}
	return 0;
}
