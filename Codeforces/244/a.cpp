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
	int n;
	cin>>n;
	int p=0;
	int ans=0;
	while(n--)
	{
		int temp;
		cin>>temp;
		if(temp>0)
			p+=temp;
		if(temp<0)
		{
			if(p>0)
			{
				p--;
				continue;
			}
			else
				ans+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
