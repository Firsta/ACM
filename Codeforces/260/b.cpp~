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

int mod2[4]={
	1,2,4,3
};

int mod3[4]={
	1,3,4,2
};

int mod4[4]={
	1,4,1,4
};

int main(){
	string n;
	cin>>n;
	int tmp=0;
	for(int i=0;i<n.size();i++){
		tmp*=10;
		tmp+=n[i]-'0';
		tmp=tmp%4;
	}
	tmp%=4;
	cout<<(1+mod2[tmp]+mod3[tmp]+mod4[tmp])%5;
	return 0;
}
