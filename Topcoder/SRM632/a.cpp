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

int mark[100];
vector<int> a;

class RunningAroundPark{
	public:
		int numberOfLap(int N,vector<int> d){
			int cnt=0,last=N;
			for(int i=0;i<d.size();i++){
				if(d[i]<=last){
					cnt++;
				}
				last=d[i];
			}
			return cnt;
		}
};
