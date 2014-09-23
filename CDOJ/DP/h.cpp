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

int dp[100005][305];
int mark[100005][305];
vector<int> s1;
vector<int> pos[100005];

int main()
{
	int n,m,s,e;
	scanf("%d%d%d%d",&n,&m,&s,&e);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		s1.push_back(temp);
	}
	for(int i=0;i<m;i++)
	{
		int temp;
		scanf("%d",&temp);
		pos[temp].push_back(i+1);
	}
	int max=s/e;
	max=min(max,n);
	for(int i=0;i<n;i++)
		for(int j=1;j<=max;j++)
		{
			if(j>i+1)
				dp[i+1][j]=0;
			else
			{
				int lastpos=dp[i][j-1];
				int temp=lower_bound(pos[s1[i]].begin(),pos[s1[i]].end(),lastpos)-pos[s1[i]].begin();
//				cout<<temp;
//				cout<<"i:";
				if(lastpos==0&&j!=1)
				{
					dp[i+1][j]=dp[i][j];
					mark[i+1][j]=mark[i][j];
				}
				else if(temp==pos[s1[i]].size())
				{
					dp[i+1][j]=dp[i][j];
					mark[i+1][j]=mark[i][j];
//					cout<<1<<endl;
				}
				else
				{
//					cout<<2<<endl;
					int t2=pos[s1[i]][temp];
					if(dp[i][j]==0)
					{
						if(i==0)
						{
							dp[i+1][j]=t2;
							mark[i+1][j]=i+1;
						}
						else if(dp[i][j-1]!=0)
						{
							dp[i+1][j]=t2;
							mark[i+1][j]=i+1;
						}
						else
						{
							dp[i+1][j]=0;
							mark[i+1][j]=0;
						}
					}
					else if(dp[i][j]<=t2)
					{
						dp[i+1][j]=dp[i][j];
						mark[i+1][j]=mark[i][j];
					}
					else
					{
						dp[i+1][j]=t2;
						mark[i+1][j]=i+1;
					}
				}
			}
		}
/*	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
		{
			cout<<"dp["<<i<<']'<<'['<<j<<']'<<':'<<dp[i][j];
			cout<<endl;
		}*/
	for(int j=max;j>=1;j--)
	{
		if(mark[n][j]==0||dp[n][j]==0)
			continue;
		if(j*e+dp[n][j]+mark[n][j]<=s)
		{
			printf("%d\n",j);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
