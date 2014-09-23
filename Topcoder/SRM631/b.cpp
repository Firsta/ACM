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

int ha[5000],mark[5000];

class CatsOnTheLineDiv2{
	public:
		string getAnswer(vector <int> position, vector <int> count, int time){
			bool flag1=true,flag2=true;
			int n=position.size();
			for(int i=0;i<n;i++)
				ha[position[i]+2000]=count[i];
			for(int i=1000;i<=3000;i++)
				if(ha[i]>=1){
					int cnt=ha[i];
					for(int j=i-time;j<=i+time&&cnt>0;j++){
						if(mark[j]==0){
							mark[j]=1;
							cnt--;
						}
					}
					if(cnt>0)
						flag1=false;
				}
			memset(mark,0,sizeof(mark));
			for(int i=3000;i>=1000;i--)
				if(ha[i]>=1){
					int cnt=ha[i];
					for(int j=i+time;j>=i-time&&cnt>0;j--){
						if(mark[j]==0){
							mark[j]=1;
							cnt--;
						}
					}
					if(cnt>0)
						flag2=false;
				}
			if(flag1||flag2)
				return "Possible";
			else 
				return "Impossible";
		}
};
