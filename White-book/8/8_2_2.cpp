#include<cstdio>
int a[6]={
	1,2,3,3,3,5
};
int main()
{
	int x=0,y=4;
	int n;
	int m=0;
	scanf("%d",&n);
	while(x<y)
	{
		m=x+(y-x)/2;
		if(a[m]==n)
			break;
		else if(a[m]<n)
			x=m+1;
		else
			y=m;
	}
	printf("%d",m);
	return 0;
}
