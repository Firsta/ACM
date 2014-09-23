#include<iostream>
#include<cstdio>
#include<cmath>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double r,b,m;
		scanf("%lf %lf %lf",&r,&b,&m);
		int i;
		for(i=1;i<=1200;i++){
			double tt=b*r;
	//		tt=floor(tt+0.5);
	//		b+=(tt/100.0);
			b*=100;
			b+=tt;
			b=floor(b+0.5);
			b/=100;
			if(m>=b)
				break;
			else
				b-=m;
	//		cout<<b<<"!"<<' ';
		}
		//cout<<endl;
		if(i>1200)
			printf("impossible\n");
		else
			printf("%d\n",i);
	}
	return 0;
}
