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

class GreaterGameDiv2{
	public:
		int calc(vector <int> snuke, vector <int> sothe){
			int n=snuke.size();
			int ans=0;
			for(int i=0;i<n;i++){
				if(snuke[i]>sothe[i])
					ans++;
			}
			return ans;
		}
};
