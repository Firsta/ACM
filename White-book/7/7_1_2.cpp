#include<cstdio>
#include<climits>
int x[18];
int main()
{
	int n;
	scanf("%d",&n);
	long long max=LONG_LONG_MIN;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(int i=0;i<n;i++)
		for(int j=i;j<=n;j++)
		{
			long long temp=1;
			for(int k=i;k<j;k++)
			{
				temp*=x[k];
			}
			if(temp>max)
				max=temp;
		}
	printf("%lld",max);
}
