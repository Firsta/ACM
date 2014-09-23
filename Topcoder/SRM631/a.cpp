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

using namespace std;

class TaroGrid{
	public:
		int getNumber(vector<string> grid){
			int n=grid.size();
			int ans=0;
			for(int j=0;j<n;j++){
				char last='n';
				int cnt=0;
				for(int i=0;i<n;i++){
					if(grid[i][j]==last){
						cnt++;
					}else{
						cnt=1;
					}
					last=grid[i][j];
					ans=max(ans,cnt);
				}
			}
			return ans;
		}
};
