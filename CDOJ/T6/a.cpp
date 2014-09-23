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

int a[26];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		string s1,s2;
		memset(a,0,sizeof(a));
		cin>>s1;
		for(int i=0;i<s1.size();i++)
		{
			a[s1[i]-'A']++;
		}
		cin>>s2;
		bool flag=true;
		for(int i=0;i<s2.size();i++)
		{
			if(a[s2[i]-'A']==0)
			{
				flag=false;
				break;
			}
			else
				a[s2[i]-'A']--;
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
