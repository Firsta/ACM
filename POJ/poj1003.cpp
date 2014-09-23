#include<cstdio>
double tmp,c;
int i;
int main(){
	while(~scanf("%lf",&c)&&c!=0.00){
		tmp=0.0;
		for(i=2;;i++){
			tmp+=1.0/(double)i;
			if(tmp>=c)
				break;
		}
		printf("%d card(s)\n",i-1);
	}
	return 0;
}
