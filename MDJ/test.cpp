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
	int l,r;
	cin>>l>>r;
	int L=(l-1)%5+1;
	int R=(r-1)%5+1;
	int num=((r-l+1)-(5-L+1)%5-R%5)/5;
	if (num<0) num=0;
	cout<<num<<endl;
	return 0;
}
