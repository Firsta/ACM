#include<iostream>
using namespace std;
int main()
{
	int n;
	int ans;
	cin>>n;
	ans=n/1;
	cin>>n;
	ans=ans<=n/1?ans:n/1;
	cin>>n;
	ans=ans<=n/2?ans:n/2;
	cin>>n;
	ans=ans<=n/7?ans:n/7;
	cin>>n;
	ans=ans<=n/4?ans:n/4;
	cout<<ans;
	return 0;
}
