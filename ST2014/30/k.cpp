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

int ca(int x){
	if(x==0)
		return 10;
	if(x==1)
		return 50;
	if(x==2)
		return 100;
	if(x==3)
		return 500;
	if(x==4)
		return 1000;
	if(x==5)
		return 5000;
}

int cost[6];

int main(){
	int ticket;
	int sum=0;
	for(int i=0;i<6;i++){
		cin>>cost[i];
		sum+=cost[i]*ca(i);
	}
	cin>>ticket;
	int maxx=sum/ticket;
	int minn;
	for(int i=0;i<6;i++){
		if(ca(i)>ticket){
			minn=(sum-ca(i))/ticket+1;
		}
	}
	cout<<maxx-minn;
	return 0;
}
