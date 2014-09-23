#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<sstream>
#include<string>

typedef long long ll;
using namespace std;

int w[26];

int main()
{
	string s;int k;
	cin>>s;
	cin>>k;
	int maxx=0,t;
	for(int i=0;i<26;i++)
	{
		cin>>w[i];
		if(w[i]>maxx)
		{
			maxx=w[i];
			t=i;
		}
	}
	ll ans=0;
	for(int i=0;i<s.size();i++)
		ans+=(i+1)*w[s[i]-'a'];
	for(int i=0;i<k;i++)
		ans+=(s.size()+i+1)*maxx;
	cout<<ans<<endl;
	return 0;
}
