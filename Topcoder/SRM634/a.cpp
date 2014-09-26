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
typedef unsigned long long ull;
using namespace std;

class MountainRanges{
	public:
		int countPeaks(vector <int> heights){
			int n=heights.size();
			int ans=0;
			for(int i=0;i<n;i++){
				if(i==0&&heights[i]>heights[i+1])
					ans++;
				else if(i==n-1&&heights[i]>heights[i-1])
					ans++;
				else if(heights[i]>heights[i+1]&&heights[i]>heights[i-1])
					ans++;
			}
			return ans;
		}
};
