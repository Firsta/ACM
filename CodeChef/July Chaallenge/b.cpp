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

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		if(a<0)
			a=-a;
		if(b<0)
			b=-b;
		if(b>=a)
		{
			if((b-a)%2==0)
				cout<<2*a+2*(b-a)<<endl;
			else
				cout<<2*a+2*(b-a-1)+1<<endl;
		}
		else
		{
			if((a-b)%2==0)
				cout<<2*b+2*(a-b)<<endl;
			else
				cout<<2*b+((a-b+1)/2-1)*4+3<<endl;
		}
	}
	return 0;
}
