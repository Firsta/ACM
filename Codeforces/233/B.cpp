#include<iostream>
using namespace std;
int main()
{
	int n;
	long long f[51];
	f[1]=1;f[2]=2;
	for(int i=3;i<=50;i++)
	{
		long long tot=0;
		for(int j=1;j<i;j++)
			tot+=f[j];
		f[i]=tot+1ll;
	}
	string t;
	long long cnt=0;
	cin>>n;
	cin>>t;
	for(int i=0;i<n;i++)
	{
		if(t[i]=='B')
			cnt+=f[i+1];
	}
	cout<<cnt<<endl;
	return 0;
}
