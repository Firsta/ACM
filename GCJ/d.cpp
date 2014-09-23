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
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++)
	{
		int r,c,m;
		cin<<r<<c<<m;
		if(c==1)
		{
			if(r-m<2)
			{
				printf("Case #%d:\n");
				printf("Impossible\n");
				continue;
			}
			else
			{
				printf("Case #%d:\n");
				printf("*\n");
				for(int i=1;i<r-m-1;i++)
					printf(".\n");
				for(int i=0;i<m;i++)
					printf("*\n");
				continue;
			}
		}
		if(c==2)
		{
			if(r*c-m<4)
			{
				printf("Case #%d:\n");
				printf("Impossible\n");
				continue;
			}
			else
			{
				printf("Case #%d:\n");
				printf("*.\n");
				for(int i=0;i<r*c)
			}
		}
	}
	return 0;
}
