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

string s[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main(){
	string a;
	int n;
	cin>>n;
	cin>>a;
	int ans,maxx=0;
	for(int i=0;i<8;i++){
		if(s[i].size()==n){
			int f=0;
			for(int j=0;j<a.size();j++){
				if(a[j]==s[i][j]){
					f++;
				}
			}
			if(f>maxx){
				maxx=f;
				ans=i;
			}
		}
	}
	cout<<s[ans];
	return 0;
}
