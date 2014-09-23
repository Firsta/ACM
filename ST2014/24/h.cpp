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
	string name;
	int day,month,year;
}stu[10000005];

bool cmp(const node &a,const node &b){
	if(a.year!=b.year){
		return a.year<b.year;
	}else{
		if(a.month!=b.month)
			return a.month<b.month;
		else{
			return a.day<b.day;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>stu[i].name;
		scanf("%d%d%d",&stu[i].day,&stu[i].month,&stu[i].year);		
	}
	sort(stu,stu+n,cmp);
	cout<<stu[n-1].name<<endl;
	cout<<stu[0].name<<endl;
	return 0;
}
