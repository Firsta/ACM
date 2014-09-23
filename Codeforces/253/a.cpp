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

int hash[27];

int main(){
	string s;
	getline(cin,s);
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z'&&!hash[s[i]-'a']){
			cnt++;
			hash[s[i]-'a']=1;
		}
	}
	cout<<cnt;
	return 0;
}
