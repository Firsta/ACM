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
	while(cin>>s){
		for(int i=0;i<(int)s.size();i++){
			string tmp;
			if((int)s.size()-i>=5){
				tmp=s.substr(i,5);
				if(tmp=="Apple"){
					printf("MAI MAI MAI!\n");
					continue;
				}
			}
			if((int)s.size()-i>=6){
				tmp=s.substr(i,6);
				if(tmp=="iPhone"){
					printf("MAI MAI MAI!\n");
					continue;
				}
			}
			if((int)s.size()-i>=4){
				tmp=s.substr(i,4);
				if(tmp=="iPad"||tmp=="iPod"){
					printf("MAI MAI MAI!\n");
					continue;
				}else if(tmp=="Sony"){
					printf("SONY DAFA IS GOOD!\n");
					continue;
				}
			}
		}
	}
	return 0;
}
