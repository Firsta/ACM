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

ll a[305];

int main()
{
	int p,n;
	cin>>p>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	set<int> s;
	for(int i=0;i<n;i++)
	{
		if(s.count(a[i]%p))
		{
			cout<<i+1<<endl;
			return 0;
		}
		else
			s.insert(a[i]%p);
	}
	cout<<-1<<endl;
	return 0;
}
