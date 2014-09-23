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

int G[1005][1005],ew[1005],eiq[1005],d[1005],n=0;

int dp(int x)
{
	int &ans=d[x];
	if(ans>0)
		return ans;
	ans=1;
	for(int i=0;i<n;i++)
		if(G[x][i]&&dp(i)+1>ans)
			ans=dp(i)+1;
	return ans;
}

void print_ans(int i)
{
	cout<<i+1<<endl;
	for(int j=0;j<n;j++)
		if(G[i][j]&&d[i]==d[j]+1)
		{
			print_ans(j);
			break;
		}
}

int main()
{
	int weight,iq;
	while(cin>>weight>>iq)
	{
		ew[n]=weight;
		eiq[n]=iq;
		n++;
	}
	for(int i=0;i<n;i++)
		cin>>ew[i]>>eiq[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(ew[i]<ew[j]&&eiq[i]>eiq[j])
				G[i][j]=1;
	int max=0,maxi;
	for(int i=0;i<n;i++)
		if(max<dp(i))
		{
			max=dp(i);
			maxi=i;	
		}
	cout<<max<<endl;
	print_ans(maxi);
	return 0;
}
