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

string j[105];

int main(){
	j[1]="((A0|B0)|(A0|B0))";
	for(int i=1;i<=100;i++){
		string ta="A";
		string sa,sb;
		stringstream ssa,ssb;
		ssa<<i;
		ssa>>sa;
		ta+=sa;
		string tb="B";
		tb+=sa;
		string la="A";
		ssb<<(i-1);
		ssb>>sb;
		la+=sb;
		string lb="B";
		lb+=sb;
		j[i+1]="(("+ta+"|"+tb+")|("+j[i]+"|(("+ta+"|"+ta+")|("+tb+"|"+tb+")))"+")";
	}
	int n;
	scanf("%d",&n);
	cout<<j[n]<<endl;
	return 0;
}
