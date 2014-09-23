/************************************************
 * Author:		iiip
 * File name:		10285.cpp
 * Created time:	2014/4/6 20:35:41
 * Email:		firstawhois@gmail.com
 * *********************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cmath>
using namespace std;

int G[105][105];
int m[105][105];
int dx[4]={
	1,-1,0,0
};
int dy[4]={
	0,0,1,-1
};
int r,c;
int dp(int x,int y)
{
	int &ans=m[x][y];
	if(ans>0)
		return ans;
	ans=1;
	for(int i=0;i<4;i++)
		if(x+dx[i]>0&&x+dx[i]<=r&&y+dy[i]>0&&y+dy[i]<=c&&G[x][y]>G[x+dx[i]][y+dy[i]])
			ans=max(ans,dp(x+dx[i],y+dy[i])+1);
	return ans;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string name;
		cin>>name;
		cin>>r>>c;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				cin>>G[i][j];
		memset(m,0,sizeof(m));
		int max=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if(max<dp(i,j))
					max=dp(i,j);
		cout<<name<<": ";
		cout<<max<<endl;
	}
	return 0;
}
