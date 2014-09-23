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

int main()
{
//  freopen("test.in","r",stdin);
//  freopen("test.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int comb=0;
		int ans1=0;
		for(int i=0;i<c;i++)
		{
			ans1+=50*(comb*2+1);
			comb++;
		}
		for(int i=0;i<b;i++)
		{
			ans1+=100*(comb*2+1);
			comb++;
		}
		for(int i=0;i<a;i++)
		{
			ans1+=300*(comb*2+1);
			comb++;
		}
		int ans2=0;
		comb=0;
		for(int i=0;i<a;i++)
		{
			ans2+=300*(comb*2+1);
			comb++;
		}
		for(int i=0;i<b;i++)
		{
			ans2+=100*(comb*2+1);
			comb++;
		}
		for(int i=0;i<c;i++)
		{
			ans2+=50*(comb*2+1);
			comb++;
		}
		cout<<ans2<<' '<<ans1<<endl;
	}
	return 0;
}
