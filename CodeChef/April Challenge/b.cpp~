#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		ll i,j;
		cin>>i>>j;
		ll ans=0;
		ll n1=floor(log(i)/log(2));
		ll n2=floor(log(j)/log(2));
		if(i==j)
		{
			cout<<'0'<<endl;
			continue;
		}
		if(n1==n2)
			while(i!=j)
			{
				i/=2;
				j/=2;
				ans+=2;
			}
		if(n1>n2)
		{
			for(ll k=0;k<n1-n2;k++)
				i/=2;
			ans=n1-n2;
			while(i!=j)
			{
				i/=2;
				j/=2;
				ans+=2;
			}
		}
		if(n1<n2)
		{
			for(ll k=0;k<n2-n1;k++)
				j/=2;
			ans=n2-n1;
			while(i!=j)
			{
				i/=2;
				j/=2;
				ans+=2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
