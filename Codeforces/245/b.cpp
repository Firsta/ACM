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
int des[105];
int n,k,x;

int solve(int c)
{
	int temp=2;
	while(a[c]==x)
	{
		des[c++]=1;
	}
	int i2;
	while(1)
	{
		int find=0;
		for(int i=0;i<n;i++)
		{
			if(!des[i])
			{
				int i2=i+1;
				int cnt=1;
				while(1)
				{
					if(i2>=n)
						break;
					else if(des[i2])
					{
						i2++;
						continue;
					}
					else if(a[i2]!=a[i])
						break;
					else if(a[i2]==a[i])
					{
						cnt++;
						i2++;
	//					cout<<1<<endl;
						continue;
					}
				}
	//			cout<<cnt<<endl;
				if(cnt>=3)
				{
					find=1;
					for(int j=i;j<i2;j++)
						des[j]=1;
					temp+=cnt;
					break;
				}
			}
		}
		if(!find)
			break;
	}
	//for(int i=0;i<n;i++)
	//	cout<<des[i];
	//cout<<endl;
	return temp;
}

int main()
{
	cin>>n>>k>>x;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=0;i<n;i++)
		if(a[i]==a[i+1]&&a[i]==x)
		{
			memset(des,0,sizeof(des));
			int temp=solve(i);
			if(ans<temp)
				ans=temp;
			while(a[i]==x)
				i++;
		}
	cout<<ans<<endl;
	return 0;
}
