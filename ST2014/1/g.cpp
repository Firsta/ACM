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

int main()
{
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++)
	{
		string s;
		cin>>s;
		if(s.size()%2==0)
			cout<<"Case "<<cas<<": "<<"Even"<<endl;
		else
			cout<<"Case "<<cas<<": "<<"Odd"<<endl;
	}
	return 0;
}
