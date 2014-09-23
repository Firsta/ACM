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

ll a[100100];

int main()
{
	ll n,x;
	ll ans=0;
	cin>>n>>x;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		ans+=a[i]*x;
		x--;
		if(x<1)
			x=1;
	}
	cout<<ans<<endl;
	return 0;
}
