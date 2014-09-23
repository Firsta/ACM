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
#define MAXN 100005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int a[MAXN];

struct node{
	double avg;
	int amo;
	int cnt;
};

stack<node> sta;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int i=0,j=n-1;
		while(a[i]==0&&i<n)
			i++;
		while(a[j]==1&&j>=0)
			j--;
		if(i>=j){
			printf("0.000000\n");
			continue;
		}
		int cnt=0,amo=0;
		for(;i<=j;i++){
			cnt++;
			if(a[i]==1)
				amo++;
			if((a[i]==0&&i+1==n)||(a[i]==0&&a[i+1]==1)){
				node tmp,now;
				tmp.avg=(double)amo/(double)cnt;
				tmp.cnt=cnt;
				tmp.amo=amo;
				while(1){
					if(sta.size()==0||tmp.avg>=sta.top().avg){
						sta.push(tmp);
						break;
					}
					else{
						now=sta.top();
						sta.pop();
						tmp.cnt=tmp.cnt+now.cnt;
						tmp.amo=tmp.amo+now.amo;
						tmp.avg=(double)tmp.amo/(double)tmp.cnt;
					}
				}
				cnt=0;
				amo=0;
			}
		}
//		cout<<sta.size()<<'!'<<endl;
//		cout<<sta.top().cnt<<' '<<sta.top().amo<<' '<<sta.top().avg<<endl;
		double ans=0;
		while(!sta.empty()){
			double tt=0.0;
			node now=sta.top();
			sta.pop();
			tt+=(double)now.amo*(1.0-now.avg)*(1.0-now.avg);
			tt+=(double)(now.cnt-now.amo)*now.avg*now.avg;	
//			cout<<tt<<'?'<<endl;
			ans+=tt;
		}
		printf("%.6f\n",ans);
	}
	return 0;
}
