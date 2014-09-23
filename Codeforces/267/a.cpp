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
	int cnt=0;
	for(int i=0;i<n;i++){
		int p,q;
		scanf("%d%d",&p,&q);
		if(q-p>=2)
			cnt++;
	}
	cout<<cnt;
	return 0;
}
