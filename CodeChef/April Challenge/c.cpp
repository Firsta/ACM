#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int s[100005];
string so;
int num[100005][10];
int main()
{
	int n,m;
	cin>>n>>m;
	int t;
	char c;
	cin>>so;
	for(int i=0;i<so.size();i++)
		s[i+1]=so[i]-'0';
	for(int i=1;i<=n;i++)
	{
		num[i][s[i]]++;
		for(int j=0;j<10;j++)
			num[i+1][j]=num[i][j];
	}
	while(m--)
	{
		int x;
		cin>>x;
		int sum=0;
		int a=s[x];
		for(int i=0;i<10;i++)
		{
			if(i<a)
				sum+=num[x][i]*(a-i);
			if(i>a)
				sum+=num[x][i]*(i-a);
		}
		cout<<sum<<endl;
	}
	return 0;
}
