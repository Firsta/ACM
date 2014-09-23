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

struct node{
	int a,b;
}la[100005];

bool cmp(const node &a,const node &b){
	return a.a<b.a;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>la[i].a>>la[i].b;
	sort(la,la+n,cmp);
	for(int i=0;i<n-1;i++)
		if(la[i].b>la[i+1].b){
			cout<<"Happy Alex";
			return 0;
		}
	cout<<"Poor Alex";
	return 0;
}
