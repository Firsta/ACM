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
#define MAX_N 100005

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int a[MAX_N];
int sum[MAX_N];
int res1[2*MAX_N];
int res2[2*MAX_N];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		fill(res1,res1+2*n,0);
		fill(res2,res2+2*n,0);
		int cnt=0,mm;
		for(int i=0;i<n;i++){
			if(a[i]==m){
	//			cout<<i<<endl;
				mm=i;
				cnt+=0;
			}else if(a[i]>m)
				cnt+=1;
			else
				cnt-=1;
			sum[i]=cnt;
		}
/*		for(int i=0;i<n;i++)
			cout<<sum[i]<<' ';
		cout<<endl;*/
		res1[n]=1;
		for(int i=0;i<mm;i++){
			if(i%2==0)
				res2[sum[i]+n]++;
			else
				res1[sum[i]+n]++;
		}
		int ans=0;
		for(int i=mm;i<n;i++){
			if(i%2==0)
				ans+=res1[sum[i]+n];
			else
				ans+=res2[sum[i]+n];
		}
		printf("%d\n",ans);
	}
	return 0;
}
