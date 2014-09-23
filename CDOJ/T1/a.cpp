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

int a[100100];

int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		if(n-1-i+a[i]>ans)
			ans=n-1-i+a[i];
	}
	ans+=2;
	printf("%d",ans);
	return 0;
}
