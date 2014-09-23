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

int a[19],b[10];
ll dp[1<<18][100];

int main()
{
	ll n;int m;
	cin>>n>>m;
	int len=0;
	while(n)
	{
		b[n%10]++;
		a[len++]=n%10;
		n/=10;
	}
	dp[0][0]=1;//0%m=0
	for(int i=0;i<(1<<len);i++)
		for(int j=0;j<len;j++)
			if(!(i&1<<j)&&(i||a[j]))//no leading zeors
				for(int k=0;k<m;k++)
					dp[i|(1<<j)][(k*10+a[j])%m]+=dp[i][k];
	ll ans=dp[(1<<len)-1][0];
	for(int i=0;i<=9;i++)
		for(int j=2;j<=b[i];j++)
			ans/=j;
	cout<<ans<<endl;
	return 0;
}
