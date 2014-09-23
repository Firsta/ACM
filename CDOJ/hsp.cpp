#include<iostream>
using namespace std;
int lock[100005];
int key[100005];
int rooms[100005];
int main()
{
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		int n,m;
		cin>>n>>m;
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			rooms[u]=v;
			rooms[v]=u;
		}
		int p;
		cin>>p;
		while(p--)
		{
			int x,y;
			cin>>x>>y;
			
		}
	}
}
