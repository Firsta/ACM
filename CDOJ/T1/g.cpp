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

char re(char c)
{
	if(c=='1')
		return '0';
	else
		return '1';
}

int main()
{
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1;cin>>s2;
	int len1=s1.size(),len2=s2.size();
	if(len1!=len2)
	{
		cout<<"Deletion failed";
		return 0;
	}
	int flag=1;
	if(n%2==1)
		for(int i=0;i<s1.size();i++)
			if(s1[i]!=re(s2[i]))
			{
				flag=0;
				break;
			}
	if(n%2==0)
		for(int i=0;i<s1.size();i++)
			if(s1[i]!=s2[i])
			{
				flag=0;
				break;
			}
	if(flag)
		cout<<"Deletion succeeded";
	else
		cout<<"Deletion failed";
	return 0;
}
