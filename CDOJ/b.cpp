#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long b[10000];
long long find(long long x)
{
	for(long long i=2;i<=floor(sqrt(x)+0.5);i++)
	{
		if(x%i==0)
			return i;
	}
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
		}
		if(n==1)
		{
			printf("Case #%d: Good Function\n",cas);
			continue;
		}
		sort(b,b+n);
		if(b[n-2]==1||b[n-2]==0)
		{
			printf("Case #%d: Good Function\n",cas);
			continue;
		}
		long long i;
		for(i=b[n-1]+1;;i++)
		{
			int y=find(i);
			if(y>b[n-2]||y==1)
				break;
		}
		printf("Case #%d: %lld\n",cas,i);
	}
	return 0;
}
