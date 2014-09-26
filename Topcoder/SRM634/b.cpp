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

class ShoppingSurveyDiv2{
	public:
		int minValue(int N, vector <int> s){
			int n=N,m=s.size();
			if(m==1)
				return s[0];
			int minn=INT_MAX,sum=0;
			for(int i=0;i<m;i++){
				minn=min(minn,s[i]);
				sum+=s[i];
			}
			int i;
			for(i=0;i<=minn;i++){
				int ts=sum-m*i;
				if(ts<=(n-i)*(m-1))
					break;
			}
			return i;
		}
};
