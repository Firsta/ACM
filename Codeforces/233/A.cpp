#include<iostream>
using namespace std;
int main()
{
	int n,p,k;
	cin>>n>>p>>k;
	int flag1=0;
	int flag2=0;
	if(p-k>1)
	{
		cout<<"<< ";
		flag1=1;
	}
	if(p+k<n)
		flag2=1;
	if(flag1)
		for(int i=p-k;i<p;i++)
			cout<<i<<' ';
	else
		for(int i=1;i<p;i++)
			cout<<i<<' ';
	cout<<'('<<p<<')';
	if(flag2)
	{
		for(int i=p+1;i<=p+k;i++)
			cout<<' '<<i;
		cout<<" >>"<<endl;
	}
	else
	{
		for(int i=p+1;i<=n;i++)
			cout<<' '<<i;
		cout<<endl;
	}
	return 0;
}
