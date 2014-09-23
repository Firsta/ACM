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
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		if(s.find("D")!=-1){
			cout<<"You shall not pass!"<<endl;
		}else
			cout<<"Possible"<<endl;
	}
	return 0;
}
