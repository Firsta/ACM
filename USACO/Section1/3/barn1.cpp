/*
ID: firstaw1
PROG: barn1
LANG: C++
*/
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

int a[205];
int mark[205];
int m,s,c;

int findMax()
{
	bool flag=false;
	int ans=0,tl,l=0,r=1;
	int cnt=0;bool find=false;
	for(int i=a[0];i<=a[c-1];i++)
	{
		if(mark[i]==0&&flag==false)
		{
			flag=true;
			tl=i;
			cnt=1;
			find=true;
		}
		else if(mark[i]==1&&flag==true)
		{
			flag=false;
			if(cnt>ans)
			{
				ans=cnt;
				r=i-1;
				l=tl;
			}
		}
		else if(mark[i]==0&&flag==true)
		{
			cnt++;
		}
	}
	if(!find)
		return 0;
	for(int i=l;i<=r;i++)
		mark[i]=1;
	return r-l+1;
}

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
	cin>>m>>s>>c;
	for(int i=0;i<c;i++)
		cin>>a[i];
	sort(a,a+c);
//	for(int i=0;i<c;i++)
//		cout<<a[i]<<' ';
//	cout<<endl;
	int ans=a[c-1]-a[0]+1;
	for(int i=0;i<c;i++)
		mark[a[i]]=1;
	for(int i=0;i<m-1;i++)
	{
		int t=findMax();
//		cout<<"t:"<<t<<endl;
		ans-=t;
	}
	cout<<ans<<endl;
	return 0;
}
