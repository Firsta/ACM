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

class Subsets
{
	public:
		int findSubset(vector<int> numbers)
		{
			int temp[1000];
			int len=numbers.size();
			for(int i=0;i<numbers.size();i++)
			{
				temp[i]=numbers[i];
			}
			sort(temp,temp+len);
			int i=0;
			while(temp[i]==1)
				i++;
			int sum1=i;
			int ans=0;
			int sum=0;
			int pro=1;
			while(1)
			{
				sum+=temp[i];
				pro*=temp[i];
				int t2=pro-sum;
				if (t2<=sum1)
					ans++;
				else
					break;
				i++;
			}
			return ans;
		}
};
