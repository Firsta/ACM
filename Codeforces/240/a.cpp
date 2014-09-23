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
int l[105];

int main()
{
	int n,m;
	cin>>n>>m;
	int t;
	for(int i=1;i<=m;i++)
	{
		cin>>t;
		for(int i=t;i<=n;i++)
			if(l[i]==0)
				l[i]=t;
	}
	for(int i=1;i<n;i++)
		cout<<l[i]<<' ';
	cout<<l[n]<<endl;
	return 0;
}
