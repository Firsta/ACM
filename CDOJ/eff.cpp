#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long ans;
		if(a==0)
			ans=1;
		else if(c==0)
			ans=a+2*b+1;
		else if(a+2*b<4&&c!=0)
			ans=a+2*b+1;
		else 
			ans=a+2*b+5*c+1;
		printf("Case #%d: %lld\n",i,ans);
	}
	return 0;
}
