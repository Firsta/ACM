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

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int a1=0,a2=0;
	for(int i=0;i<s1.size();i++)
		a1=a1*10+(int)(s1[i]-'0');
	for(int i=0;i<s2.size();i++)
		a2=a2*10+(int)(s2[i]-'0');
	if(a1%2==0||a2%2==1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
