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

int find2(int n)
{
	int res=1;
	while(res<n)
		res*=2;
	return res;
}

class BoxesDiv2
{
	public:
		int findSize(vector<int> candyCounts)
		{
			vector<int> b1;
			for(int i=0;i<candyCounts.size();i++)
			{
				int temp=find2(candyCounts[i]);
				b1.push_back(temp);
			}
			int sum=0;
			for(int i=0;i<b1.size();i++)
				sum+=b1[i];
			int ans=find2(sum);
			return ans;
		}
};
