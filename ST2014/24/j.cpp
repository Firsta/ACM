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

int main(){
	string s;
	int maxx=0;
	vector<char> ans;
	while(cin>>s&&s!="E-N-D"){
		vector<char> word;
		for(int i=0;i<s.size();i++)
			if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]=='-')){
				word.push_back(s[i]);
			}
		if(word.size()>maxx){
			maxx=word.size();
			ans=word;
		}
	}
	for(int i=0;i<ans.size();i++)
		printf("%c",tolower(ans[i]));
	printf("\n");
	return 0;
}
