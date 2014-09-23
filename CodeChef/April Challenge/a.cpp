#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
int main()
{
	int t;
	int x,y;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		int i;
		for(i=x+y+1;;i++)
			if(isprime(i))
				break;
		cout<<i-x-y<<endl;
	}
	return 0;
}
