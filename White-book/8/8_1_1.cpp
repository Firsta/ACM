#include<cstdio>
int a[100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int tot=0;
	int best=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=a[k];
			}
			if(sum>best)
				best=sum;
		}
	printf("%d",best);
}
