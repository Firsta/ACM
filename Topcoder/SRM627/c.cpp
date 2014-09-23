#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int r[55][55],dp[55][55];

int count(vector<int> B,int x){
	int cnt=0;
	for(int i=x;i<B.size();i++)
		for(int j=0;j<i;j++){
			if(B[j]>B[i])
				cnt++;
		}
	return cnt;
}

class BubbleSortWithReversals {
public:
	int getMinSwaps(vector <int>, int);
};

int BubbleSortWithReversals::getMinSwaps(vector <int> A, int K) {
	int n=A.size();
	for(int i=0;i<=K;i++)
		dp[n-1][i]=0;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=K;j++){
			vector<int> B(A.begin(),A.begin()+i+1);
			int t1=count(B,i);
			dp[i][j]=t1+dp[i+1][j];
			if(j>=1){
				for(int y=i+1;y<n;y++){
					vector<int> B(A.begin(),A.begin()+y+1);
					reverse(B.begin()+i,B.begin()+y+1);
					int t2=count(B,i);
					dp[i][j]=min(dp[i][j],t2+dp[i+1][j-1]);
				}
			}
		}
	}
	return dp[0][K];
}
