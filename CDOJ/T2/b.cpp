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

int t1[1001],t2[1001];
int vis1[1001],vis2[1001];

int main()
{
	int n1,n2,m,cas=0;
	while(cin>>n1>>n2>>m)
	{
		cas++;
		if(!n1&&!n2&&!m)
			break;
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		int flag1=0,flag2=0;
		while(m--)
		{
			int temp;
			scanf("%d",&temp);
			int turn=0;
			while(1)
			{
				if(turn==0)
				{
					int res=temp%n1;
					if(vis1[res]==0)
					{
						t1[res]=temp;
						vis1[res]=1;
						flag1=1;
						break;
					}
					else
					{
						int ch=t1[res];
						t1[res]=temp;
						temp=ch;
						turn=1;
						continue;
					}
				}
				else
				{
					int res=temp%n2;
					if(vis2[res]==0)
					{
						t2[res]=temp;
						vis2[res]=1;
						flag2=1;
						break;
					}
					else
					{
						int ch=t2[res];
						t2[res]=temp;
						temp=ch;
						turn=0;
						continue;
					}
				}
			}
		}
		cout<<"Case "<<cas<<':'<<endl;
		if(flag1)
		{
			cout<<"Table 1"<<endl;
			for(int i=0;i<n1;i++)
				if(vis1[i])
					cout<<i<<':'<<t1[i]<<endl;
		}
		if(flag2)
		{
			cout<<"Table 2"<<endl;
				for(int i=0;i<n2;i++)
				if(vis2[i])
					cout<<i<<':'<<t2[i]<<endl;
		}
	}
	return 0;
}
