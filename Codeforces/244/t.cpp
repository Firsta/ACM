#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<sstream>
#include<vector>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>

typedef long long ll;
using namespace std;

int main()
{
	string a="lovlov";
	int t=a.find("lov");
	cout<<t<<endl;
	cout<<a.find("lov",t+1);
	return 0;
}
