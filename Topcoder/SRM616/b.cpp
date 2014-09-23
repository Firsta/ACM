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

int r[15];
class ColorfulCoinsEasy
{
	public:
		string isPossible(vector <int> values)
		{
			if(value.size()==1)
				return "Possible";
			if(value.size()==2)
				return "Possible";
			int len=values.size();
			for(int i=values[len-2]+2;i<values[len-1];i++)
			{
				int temp=i;
				for(int j=len-2;j>=0;j--)
				{
					r[j]=temp/values[j];
					temp=temp%values[j];
				}
				sort(r,r+len-1);
				bool flag=true;
				for(int k=0;k<len-2;k++)
					if(r[k]==r[k+1])
						flag=false;
				if(flag)
					return "Possible"
			}
			return "Impossible"
		}
};
