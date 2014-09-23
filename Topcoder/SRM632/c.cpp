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

map<int> m;

int dfs(int x,vector<int> ha){
	if(s.count(x))
		return m[x];
	else{
		for(int i=1;i*i<=x;i++){
			if(ha[i]>0&&x%i==0){
				m[x]+=
			}
		}
	}
}
class GoodSubset{
	public:
		int numberOfSubsets(int goodValue, vector <int> d){
			dfs(goodValue);
			return m[goodValue];
		}
}
