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

int a[105];

int main()
{
	int n,s;
	cin>>n>>s;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int sum=0;
	for(int i=0;i<n-1;i++)
		sum+=a[i];
	if(sum<=s)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
