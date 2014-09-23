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

int xd[1005][1005];
int xdt[1005][1005];
int dp[1005],a[1005];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//zuo:-1 you:1
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(i!=j){
				if(j>i)
					xd[a[i]][a[j]]=1;
				else
					xd[a[i]][a[j]]=-1;
			}
		}
		dp[i]=n;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<xd[i][j]<<' ';
		cout<<endl;
	}
	for(int i=1;i<k;i++){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(j>i)
						xdt[a[i]][a[j]]=1;
					else
						xdt[a[i]][a[j]]=-1;
				}
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(xd[i][j]!=xdt[i][j]&&xd[i][j]!=0){
					xd[i][j]=0;
					dp[i]--;
				}
			}
		cout<<endl;
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<xd[i][j]<<' ';
		cout<<endl;
	}
		cout<<endl;
		for(int i=1;i<=n;i++)
			cout<<dp[i]<<' ';
		cout<<endl;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
