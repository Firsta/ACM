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
	int n,m;
	scanf("%d%d",&n,&m);
	int v=n*m;
	int cnt=0;
	while(v){
		n--;m--;
		v=n*m;
		cnt++;
	}
	if(cnt%2==1)
		cout<<"Akshat";
	else
		cout<<"Malvika";
	return 0;
}
