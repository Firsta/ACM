#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m1,y1;
		scanf("%d%d",&m1,&y1);
		int m2,y2;
		scanf("%d%d",&m2,&y2);
		double ans;
		if(y1==y2)
		{
			double e=0.5/(12.0-m1+1.0);
			ans=(m2-m1)*e;
			printf("%.4lf\n",ans);
			continue;
		}
		else
		{
			ans=0.5;
			y1++;
			ans+=(y2-y1)*1.0;
			ans+=(1.0/12.0)*(m2-1);
			printf("%.4lf\n",ans);
		}
	}
	return 0;
}
