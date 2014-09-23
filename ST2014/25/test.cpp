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
	fill(a,a+n,1);
	int s=n;
	while(s>1){
		for(int i=0;i<s-1;i++)
			a[i]=a[i+1]-a[i];
		s--;
	}
	return 0;
}
