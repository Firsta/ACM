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

class PotentialGeometricSequence{
	public:
		int numberOfSubsequences(vector <int> d){
			int ans=d.size();
			for(int i=0;i<d.size()-1;i++){
				int td=d[i+1]-d[i];
				for(int j=i+1;j<d.size();j++){
					if(d[j]-d[j-1]==td)
						ans++;
					else
						break;
				}
			}
			return ans;
		}
};
