/*
ID: firstaw1
PROG: milk2
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
#include<fstream>

typedef long long ll;
using namespace std;

int a[1000005];

int main()
{
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	int l,r,n;
	fin>>n;
	int minn=1000000,maxx=0;
	for(int i=0;i<n;i++)
	{
		fin>>l>>r;
		minn=min(minn,l);
		maxx=max(maxx,r);
		for(int j=l;j<r;j++)
			a[j]=1;
	}
	int flag=false;
	int ans1=0,ans2=0;
	int cnt1=0,cnt2=0;
	for(int i=minn;i<maxx;i++)
	{
		if(a[i]==0&&flag==false)
		{
			cnt2++;
			ans2=max(ans2,cnt2);
			continue;
		}
		if(a[i]==0&&flag==true)
		{
			flag=false;
			cnt2++;
			ans2=max(ans2,cnt2);
			cnt1=0;
			continue;
		}
		if(a[i]==1&&flag==false)
		{
			flag=true;
			cnt1++;
			ans1=max(ans1,cnt1);
			cnt2=0;
			continue;
		}
		if(a[i]==1&&flag==true)
		{
			cnt1++;
			ans1=max(ans1,cnt1);
			continue;
		}
	}
	fout<<ans1<<' '<<ans2<<endl;
	return 0;
}
