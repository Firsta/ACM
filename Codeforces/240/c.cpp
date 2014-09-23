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
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	ll n,k;
	cin>>n>>k;
	ll i;
	if(k<n/2)
	{
		cout<<-1;
		return 0;
	}
	if(n==1){if(k==0)puts("1");else puts("-1");return 0;}
	cout<<k-n/2+1<<' '<<2*(k-n/2+1);
	long long j=2*(k-n/2+1)+1;
	for(i=0;i<n-2;i++)
		cout<<' '<<j+i;
	return 0;
}
