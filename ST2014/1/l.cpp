#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<sstream>
#include<string>

typedef long long ll;
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			for(int j=0;j<s.size();j++)
				if(s[j]=='O')
				{
					sum++;
				}
		}
		if(sum%2==0)
			printf("Case %d: Fat brother\n",cas);
		else
			printf("Case %d: Maze\n",cas);
	}
	return 0;
}
