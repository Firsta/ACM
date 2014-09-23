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

string s,lasts;

int main(){
	lasts="";
	while(cin>>s){
		bool find=false;
		int i,j,cnt=0;
		for(i=0;i<lasts.size();i++){
			if(lasts[i]!=' '){
				find=true;
				break;
			}
			else
				cnt++;
		}
		int cnts=0;
		for(j=0;j<s.size()&&i+j<lasts.size();j++){
			if(lasts[i+j]!=s[j])
				break;
			else
				cnts++;
		}
		if(cnts>cnt){
			for(int k=0;k<cnt+1;k++)
				s=' '+s;
			cout<<s<<endl;
			lasts=s;
			continue;
		}else{
			for(int k=0;k<cnts;k++)
				s=' '+s;
			cout<<s<<endl;
			lasts=s;
			continue;
		}
	}
	return 0;
}
