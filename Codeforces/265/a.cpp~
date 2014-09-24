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

int bit[105];

int main(){
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	int i;
	for(i=0;i<s.size();i++)
		bit[i]=s[i]-'0';
	for(i=0;i<=n;i++)
		if(bit[i]==0)
			break;
	if(i==n)
		cout<<n;
	else
		cout<<i+1;
	return 0;
}
