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
	string s1,s2;
	cin>>s1;cin>>s2;
	int len1=s1.size(),len2=s2.size();
	if(len1>=len2)
	{
		int l,r;
		int fl=0,fr=0;
		for(int i=0;i<len2;i++)
			if(s1[i]!=s2[i])
			{
				fl=1;
				l=i;
				break;
			}
		for(int i=len1-1,j=len2-1;j>=0;j--,i--)
			if(s1[i]!=s2[j])
			{
				fr=1;
				r=j;
				break;
			}
		if(fl&&fr&&r>=l)
			cout<<r-l+1;
		else
			cout<<'0';
	}
	if(len2>len1)
	{
		int l,r;
		int fl=0,fr=0;
		for(int i=0;i<len1;i++)
			if(s1[i]!=s2[i])
			{
				fl=1;
				l=i;
				break;
			}
		for(int i=len1-1,j=len2-1;i>=0;j--,i--)
			if(s1[i]!=s2[j])
			{
				fr=1;
				r=j;
				break;
			}
		if(fl&&fr&&r>=l)
			cout<<r-l+1;
		else
			cout<<len2-len1;
	}
	return 0;
}
