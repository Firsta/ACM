#include<iostream>
#include<cstdio>

#define MAXN 400010
typedef long long ll;
using namespace std;

ll sumv[MAXN],addv[MAXN];

void build(ll id,ll l,ll r)
{	
	int lc=id*2,rc=id*2+1;
	addv[id]=0;
	if(l==r)
	{
		scanf("%lld",&sumv[id]);
	}
	else
	{
		ll mid=(l+r)/2;
		build(lc,l,mid);
		build(rc,mid+1,r);
		sumv[id]=sumv[lc]+sumv[rc];
	}
}

void maintain(ll id,ll l,ll r)
{
	if(addv[id]!=0)
	{
		int mid=(l+r)/2;
		addv[id*2]+=addv[id];
		addv[id*2+1]+=addv[id];
		sumv[id*2]+=(mid-l+1)*addv[id];
		sumv[id*2+1]+=(r-mid)*addv[id];
		addv[id]=0;
	}
}

void update(ll id,ll l,ll r,ll w,ll a,ll b)
{
	int lc=id*2,rc=id*2+1;
	if(a<=l&&b>=r)
	{
		addv[id]+=w;
		sumv[id]+=w*(r-l+1);
	}
	else
	{
		maintain(id,l,r);
		ll mid=(l+r)/2;
		if(a<=mid)
			update(lc,l,mid,w,a,b);
		if(b>mid)
			update(rc,mid+1,r,w,a,b);
		sumv[id]=sumv[lc]+sumv[rc];
	}
}

ll query(ll id,ll l,ll r,ll a,ll b)
{
	if(a<=l&&b>=r)
		return sumv[id];
	else
	{
		maintain(id,l,r);
		ll mid=(l+r)/2;
		ll ans=0;
		if(a<=mid)
			ans+=query(id*2,l,mid,a,b);
		if(b>mid)
			ans+=query(id*2+1,mid+1,r,a,b);
		return ans;
	}
}

int main()
{
	ll n,m;
	ll a,b,w;
	char opt[2];
	scanf("%lld%lld",&n,&m);
	build(1,1,n);
	while(m--)
	{
		scanf("%s%lld%lld",opt,&a,&b);
		if(opt[0]=='0')
		{
			printf("%lld\n",query(1,1,n,a,b));
		}
		else if(opt[0]=='1')
		{
			scanf("%lld",&w);
			update(1,1,n,w,a,b);
		}
	}
	return 0;
}
