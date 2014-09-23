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

vector<string> ans;

class Target{
	public:
		vector<string> draw(int n){
			string tmp;
			int sp=0;
			for(int i=0;i<n/2+1;i++){
				tmp="";
				if(i%2==0){
					for(int i=0;i<sp;i++)
						tmp+="# ";
					for(int i=0;i<n-4*sp;i++)
						tmp+="#";
					for(int i=0;i<sp;i++)
						tmp+=" #";
					sp++;
				}else{
					for(int i=0;i<sp;i++)
						tmp+="# ";
					for(int i=0;i<n-4*sp;i++)
						tmp+=" ";
					for(int i=0;i<sp;i++)
						tmp+=" #";
				}
				ans.push_back(tmp);
			}
			sp--;
			for(int i=n/2+1;i<n;i++){
				tmp="";
				if(i%2==0){
					sp--;
					for(int i=0;i<sp;i++)
						tmp+="# ";
					for(int i=0;i<n-4*sp;i++)
						tmp+="#";
					for(int i=0;i<sp;i++)
						tmp+=" #";
				}else{
					for(int i=0;i<sp;i++)
						tmp+="# ";
					for(int i=0;i<n-4*sp;i++)
						tmp+=" ";
					for(int i=0;i<sp;i++)
						tmp+=" #";
				}
				ans.push_back(tmp);
			}
			return ans;
		}
};
