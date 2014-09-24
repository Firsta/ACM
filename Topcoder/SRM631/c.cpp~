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

ll f[65][4];

class TaroCoins{
	public:
		long long getNumber(long long N){
			for(int i=0;i<=60;i++){
				for(int j=0;j<=3;j++){
					f[i][j]=0;
					int r=j+(((1LL<<i)&N)?1:0);
					for(int k=0;k<=j&&k<=r;k++){
						int tmp=2*(r-k);
						if(tmp<=3){
							if(i==0){
								if(tmp==0)
									f[i][j]+=1;
							}else{
								f[i][j]+=f[i-1][tmp];
							}
						}
					}
				}
			}
			return f[60][0];
		}
}
