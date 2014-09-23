#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>

typedef long long ll;
using namespace std;

ll x,y,m,n,l,k,t,r,d;

void extgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	if(!b)
	{
		d=a,x=1,y=0;
	}
	else
	{
		extgcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

int main()
{
	while(~scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l))
	{
		extgcd(n-m,l,d,k,t);
		if((x-y)%d!=0||((n-m==0)&&x!=y))
		{
			printf("Impossible\n");
			continue;
		}
		k*=((x-y)/d);
		r=l/d;
		if(r<0)
			r=-r;
		k=(k%r+r)%r;
		if(k==0&&x!=y)
			k+=r;
		printf("%lld\n",k);
	}
	return 0;
}
