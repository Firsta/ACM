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
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		int len=s.size();
		for(int i=0;i<len/2;i++){
			if(s[i]<=s[len-i-1])
				s[len-i-1]=s[i];
			else if(s[i]>s[len-i-1])

		}
	}
	return 0;
}
