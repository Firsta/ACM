#include<cstdio>
int a[1001];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	bool flag=true;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(j!=i)
				if(a[i]+a[j]==0)
				{
					flag=false;
					break;
				}
	if(flag)
		printf("UNIQUE\n");
	else
		printf("NOT UNIQUE\n");
	return 0;
}
