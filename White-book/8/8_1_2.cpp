#include<cstdio>
int a[100];
int s[100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s[0]=0;
	int best=0;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if(best<s[j]-s[i-1])
				best=s[j]-s[i-1];
		}
	printf("%d",best);
	return 0;
}
