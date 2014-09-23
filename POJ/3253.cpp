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
#include<fstream>
#include<sstream>
#include<string>

typedef long long ll;
using namespace std;

int a[20005];

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int n;
	scanf("%d",&n);
	priority_queue<int,vector<int>, greater<int> > pque;
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		pque.push(tmp);
	}
	ll ans=0;
	for(int i=0;i<n-1;i++)
	{
		int t1=pque.top();pque.pop();
		int t2=pque.top();pque.pop();
		ans+=(t1+t2);
		pque.push(t1+t2);
	}
	printf("%lld\n",ans);
	return 0;
}
