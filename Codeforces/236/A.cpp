#include<iostream>
using namespace std;
int main()
{
	int k,a,b,v;
	cin>>k>>a>>b>>v;
	int n1;
	n1=a/(k*v);
	int n;
	if(n1==0)
	{
		n=1;
		if(b<k-1)
		{
			a-=(b+1)*v;
			if(a>0)
				n+=a/v+(a%v?1:0);
		}
	}
	else if(n1*(k-1)<=b)
		n=n1+(a%(k*v)?1:0);
	else if(n1*(k-1)>b)
	{
		n=b/(k-1);
		a-=(b/(k-1))*k*v;
		if(b%(k-1))
		{
			a-=(b%(k-1)+1)*v;
			n++;
		}
		n+=a/v+(a%v?1:0);
	}
	cout<<n;
}
