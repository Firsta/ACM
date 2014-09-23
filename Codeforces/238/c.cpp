#include<iostream>
#include<cstdio>
using namespace std;
int m[1005][1005];
int main()
{
	int n;
	scanf("%d",&n);
	bool ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&m[i][j]);
			if(i==j) ans^=m[i][j];
		}
	long long q;
	scanf("%I64d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d",&a);
		if(a!=3)
			scanf("%d",&b);
		if(a==3)
		{
			printf("%d",ans);
		}
		else
		{
			ans^=1;
		}
	}
	return 0;
}
