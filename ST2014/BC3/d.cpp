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

int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(){
	int m;
	int cnt=1;
	for(m=1;m<20;m++){
		cnt=1;
		for(int i=1;i<=m;i++)
			if(gcd(i,m)==1)
				cnt*=i;
		cout<<cnt%m<<endl;
	}
	return 0;
}
