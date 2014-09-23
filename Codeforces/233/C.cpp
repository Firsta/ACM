#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
	ll a,b;
	cin>>a>>b;
	ll ans=0;
	ll bn,by;
	ll an=1;
	if(a==0)
	{
		ans-=b*b;
		cout<<ans<<endl;
		for(ll i=0;i<b;i++)
			cout<<'x';
		cout<<endl;
		return 0;
	}
	else
	{
		ll temp=0;
		ll i;
		for(i=1;i<=a;i++)
		{
			temp=0;
			temp+=i-1+(a-i+1)*(a-i+1);
			bn=b/(i+1);
			by=b%(i+1);
			temp-=by*(bn+1)*(bn+1)+(i+1-by)*bn*bn;
			if(i==1)
				ans=temp;
			if(temp>ans)
			{
				ans=temp;
				an=i;
			}
		}
	}
	cout<<ans<<endl;
	bn=b/(an+1);
	by=b%(an+1);
	for(ll i=0;i<by;i++)
	{
		for(ll j=0;j<bn+1;j++)
			cout<<'x';
		cout<<'o';
	}
	for(ll i=0;i<an-by;i++)
	{
		for(ll j=0;j<bn;j++)
			cout<<'x';
		cout<<'o';
	}
	for(ll i=0;i<a-an;i++)
		cout<<'o';
	for(ll i=0;i<bn;i++)
		cout<<'x';
	cout<<endl;
	return 0; 
}
