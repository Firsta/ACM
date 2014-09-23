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

int cnt[1005];

class ManySquares {
public:
	int howManySquares(vector <int>);
};

int ManySquares::howManySquares(vector <int> sticks) {
	int ans=0;
	for(int i=0;i<sticks.size();i++)
	{
		cnt[sticks[i]]++;
		if(cnt[sticks[i]]==4)
		{
			ans++;
			cnt[sticks[i]]=0;
		}
	}
	return ans;
}
