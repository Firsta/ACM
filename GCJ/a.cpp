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

int card[4][4];
int vis[17];

int main()
{
	int t;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for(int cas=1;cas<=t;cas++)
	{
		int l;
		cin>>l;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin>>card[i][j];
		for(int i=0;i<4;i++)
			vis[card[l-1][i]]++;
		cin>>l;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin>>card[i][j];
		for(int i=0;i<4;i++)
			vis[card[l-1][i]]++;
		int ans;
		int cnt=0;
		for(int i=1;i<=16;i++)
			if(vis[i]==2)
			{
				ans=i;
				cnt++;
			}
		if(!cnt)
			cout<<"Case #"<<cas<<": "<<"Volunteer cheated!"<<endl;
		if(cnt>1)
			cout<<"Case #"<<cas<<": "<<"Bad magician!"<<endl;
		if(cnt==1)
			cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}
