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

bool check(string x){
	bool flag=true;
	string t1,t2;
	for(int i=1;i<x.size();i++){
		t1=x.substr(0,i);
		t2=x.substr(i);
		if(t1>=t2){
			flag=false;
			break;
		}
	}
	return flag;
}

class SpecialStrings{
	public:
		string findNext(string current){
			string s=current;
			int n=s.size();
			if(s=="1")
				return "";
			else if(s=="0")
				return "1";
			int ind=-1;
			for(int i=n-1;i>=0;i--)
				if(s[i]=='0'){
					s[i]='1';
					ind=i;
					break;
				}
			string tmp;
			for(int i=ind+1;i<n;i++){
				tmp=s;
				tmp[i]='0';
				if(check(tmp))
					return tmp;
			}
			if(check(s))
				return s;
			return "";
		}
};
