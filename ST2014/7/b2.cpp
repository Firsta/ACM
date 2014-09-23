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
#define MAXN 100100

typedef long long ll;
using namespace std;

char str[MAXN],ts[MAXN*2+1];
int p[MAXN*2+1];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		memset(p,0,sizeof(p));
		memset(ts,0,sizeof(ts));
		ts[0]='$';ts[1]='#';
		int cnt=2;
		for(int i=0;i<strlen(str);i++){
			if(str[i]!=str[i+1]){
				ts[cnt++]=str[i];
				ts[cnt++]='#';
			}
		}
		ts[cnt]='*';
//		for(int i=0;i<=cnt;i++)
//			cout<<ts[i];
//		cout<<endl;
		int id=1,mx=0,ans=0;
		for(int i=1;i<cnt;i++){
			if(mx>i)
				p[i]=min(p[2*id-i],mx-i);
			else
				p[i]=1;
			while(ts[i+p[i]]==ts[i-p[i]])
				p[i]++;
			if(p[i]+i>mx){
				id=i;
				mx=p[i]+i;
			}
			ans=max(ans,p[i]);
		}
//		for(int i=0;i<=cnt;i++)
//			cout<<p[i]<<' ';
//		cout<<endl;
		printf("%d\n",ans/2);
	}
	return 0;
}
