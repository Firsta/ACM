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
	int n;
	scanf("%d",&n);
	while(n--){
		string s;
		cin>>s;
		if(s[s.size()/2]==s[s.size()/2-1])
			printf("Do-it\n");
		else
			printf("Do-it-Not\n");
	}
	return 0;
}
