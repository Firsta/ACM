#include<iostream>
#include<cstdio>
using namespace std;
int vis[4001];
int main()
{
	int x,k;
	cin>>x>>k;
	char s[2];
	for(int i=0;i<k;i++)
	{
		scanf("%s",s);
		if(s[0]=='1')
		{
			int a,b;
			cin>>a>>b;
			vis[a]=1;
			vis[b]=1;
		}else if(s[0]=='2')
		{
			int a;
			cin>>a;
			vis[a]=1;
		}
	}
	int max=0,min=0;
	for(int i=1;i<x;i++)
		if(!vis[i])
			max++;
	for(int i=1;i<x;i++)
		if(!vis[i])
		{
			if(!vis[i+1])
			{
				min++;
				i++;
			}else
			{
				min++;
			}
		}
	cout<<min<<' '<<max<<endl;
}
