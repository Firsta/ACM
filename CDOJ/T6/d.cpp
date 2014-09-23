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
	while(cin>>s1)
	{
		cin>>s2;
		if(s1.length()!=s2.length())
		{
			printf("no\n");
			continue;
		}
		s1=s1+s1;
		if(s1.find(s2)!=string::npos)
		{
			if(s1.find(s2)==0)
			{
				if(s1.find(s2,1)!=string::npos&&s1.find(s2,1)!=s2.size())
					printf("yes\n");
				else
					printf("no\n");
			}
			else
				printf("yes\n");
		}
		else
			printf("no\n");
	}
	return 0;
}
