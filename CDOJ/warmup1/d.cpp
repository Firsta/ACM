#include<cstdio>
#include<cmath>
int main()
{
	int c;
	scanf("%d",&c);
	int ans[20];
	for(int i=0;i<c;i++)
	{
		double r;
		int n;
		scanf("%lf%d",&r,&n);
		int temp=0;
		while(n--)
		{
			double a,b;
			scanf("%lf%lf",&a,&b);
			if(r*r>=a*a+b*b)
				temp++;
		}
		ans[i]=temp;
	}
	for(int i=0;i<c;i++)
		printf("%d\n",ans[i]);
	return 0;
}
