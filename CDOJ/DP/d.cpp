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
#define MAXN 10010

typedef long long ll;
using namespace std;

int a[MAXN];
int dp[MAXN][5010],q[MAXN];

int getdx(int l,int r)
{
	return a[r+1]-a[l+1];
}

int getdy(int l,int r,int j)
{
	return dp[r][j-1]+a[r+1]*a[r+1]-(dp[l][j-1]+a[l+1]*a[l+1]);
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=m)
	{
		cout<<0<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	//i:num j:jth room
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[i][1]=(a[i]-a[1])*(a[i]-a[1]);
	//k=2*a[i] x=a[i+1] b=dp[ans][j]-a[i]^2 y=dp[i][j]+a[i+1]^2
	for(int j=2;j<=m;j++)
	{
		int h=0,r=0;
		q[r++]=j-1;
		for(int i=j;i<=n;i++)
		{
			//maintain head;
			while(h+1<r)
			{
				int n1=q[h],n2=q[h+1];
				if(getdy(n1,n2,j)<=2*a[i]*getdx(n1,n2))
					h++;
				else
					break;
			}
			dp[i][j]=dp[q[h]][j-1]+(a[i]-a[q[h]+1])*(a[i]-a[q[h]+1]);
			//maintain rear;
			while(h+1<r)
			{
				int n1=q[r-2],n2=q[r-1];
				if(getdy(n2,i,j)*getdx(n1,n2)<=getdy(n1,n2,j)*getdx(n2,i))
					r--;
				else
					break;
			}
			q[r++]=i;
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
