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

class DoubleLetter {
public:
	string ableToSolve(string);
};

string DoubleLetter::ableToSolve(string S) {
	string s=S;
	bool find=true;
	if(s.size()==1)
		return "Impossible";
	while(find){
		find=false;
		if(s.size()==1)
			break;
		for(int i=0;i<s.size()-1;i++){
			if(s[i]==s[i+1]){
				s=s.substr(0,i+1)+s.substr(i+1);
				find=true;
				break;
			}
		}
	}
	if(s.size()==0)
		return "Possible";
	else
		return "Impossible";
}
