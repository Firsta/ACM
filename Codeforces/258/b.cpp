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

int a[100005],b[100005];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		b[i]=a[i];
	sort(b,b+n);
	int s=-1;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i]){
			s=i;
			break;
		}
	if(s==-1){
		cout<<"yes"<<endl;
		cout<<"1 1"<<endl;
		return 0;
	}
	int t=n+1;
	for(int i=n-1;i>=0;i--){
		if(a[i]!=b[i]){
			t=i;
			break;
		}
	}
	int ts=s,tt=t;
	while(ts<tt){
		int tmp=a[ts];
		a[ts]=a[tt];
		a[tt]=tmp;
		ts++;tt--;
	}
	bool flag=true;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<"yes"<<endl;
		cout<<s+1<<' '<<t+1<<endl;
	}else
		cout<<"no"<<endl;
	return 0;
}
