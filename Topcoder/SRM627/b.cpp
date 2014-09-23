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

int mark[26];

class HappyLetterDiv2 {
public:
	char getHappyLetter(string);
};

char HappyLetterDiv2::getHappyLetter(string letters) {
	int sum=0;
	for(int i=0;i<letters.size();i++)
	{
		if(mark[letters[i]-'a']==0)
			sum++;
		mark[letters[i]-'a']++;
	}
	char ans;
	for(int i=0;i<25;i++)
		if(mark[i]>sum-mark[i])
		{
			return (char)('a'+i);
		}
	return '.';
}
