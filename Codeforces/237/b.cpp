#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double a,d;
	scanf("%lf%lf",&a,&d);
	__int64 n;
	scanf("%I64d",&n);
	for(__int64 i=1;i<=n;i++)
	{
		__int64 k; 
		double t;
		t=i*d;
		k=(__int64)(t/a);
		t-=k*a;
		k%=4;
		if(k==0)
			printf("%.10lf %.10lf\n",t,0.0);
		if(k==1)
			printf("%.10lf %.10lf\n",a,t);
		if(k==2)
			printf("%.10lf %.10lf\n",a-t,a);
		if(k==3)
			printf("%.10lf %.10lf\n",0.0,a-t);
	}
	return 0;
}
