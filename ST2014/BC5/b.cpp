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
int n,v;

struct node{
	int a,b;
}bucket[50];

bool cmp(const node &a,const node &b){
	double t1=1.0*(1.0*b.b/(v-b.a)*a.a+a.b)/(v-a.a)+1.0*b.b/(v-b.a);
	double t2=1.0*(1.0*a.b/(v-a.a)*b.a+b.b)/(v-b.a)+1.0*a.b/(v-a.a);
    return t1 < t2;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&v);
		for(int i=0;i<n;i++)
			scanf("%d",&bucket[i].a);
		for(int i=0;i<n;i++)
			scanf("%d",&bucket[i].b);
		sort(bucket,bucket+n,cmp);
		bool flag=true;
		double ans=0.0;
		for(int i=0;i<n;i++){
			if(bucket[i].b==0){
				continue;
			}else if(bucket[i].a>=v){
				flag=false;
				break;
			}else{
				ans+=1.0*(bucket[i].b+ans*bucket[i].a)/((double)(v-bucket[i].a));
			}
		}
		if(!flag)
			printf("-1\n");
		else
			printf("%.0f\n",ans);
	}
	return 0;
}
